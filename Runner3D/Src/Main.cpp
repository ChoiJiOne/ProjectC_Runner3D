#include <cstdint>
#include <functional>
#include <windows.h>

#include <SDL.h>
#include <glad/glad.h>
#include <cgltf.h>

#include "CrashModule.h"
#include "Transform.h"

#include "Assertion.h"
#include "Clip.h"
#include "CrossFadeController.h"
#include "GameTimer.h"
#include "GeometryGenerator.h"
#include "GeometryPass3D.h"
#include "GLTFLoader.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "StaticMesh.h"
#include "SkinnedMesh.h"
#include "Skybox.h"
#include "SkyboxPass.h"
#include "SDLManager.h"
#include "Texture2D.h"

bool bIsDone = false;
GameTimer timer;

Mat4x4 view = Mat4x4::LookAt(Vec3f(0.0f, 10.0f, 10.0f), Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));
Mat4x4 projection = Mat4x4::Perspective(MathModule::ToRadian(45.0f), 1.25f, 0.1f, 100.0f);

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());
	
	SDLManager::Get().Startup();
	InputManager::Get().Startup();
	ResourceManager::Get().Startup();
	RenderManager::Get().Startup();

	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetMultisampleMode(true);

	InputManager::Get().AddWindowEventAction(EWindowEvent::CLOSE, [&]() {bIsDone = true; }, true);

	Shader* shader = ResourceManager::Get().GetResource<Shader>(ResourceManager::Get().Create<Shader>("Shader/Shader.vert", "Shader/Shader.frag"));

	cgltf_data* data = GLTFLoader::LoadFromFile("Resource/Model/Character.gltf");
	std::vector<GLTFLoader::SkinnedMeshData> skinnedMeshes = GLTFLoader::LoadSkinnedMeshData(data);
	std::vector<VertexPositionNormalUvSkin3D> vertices;
	std::vector<uint32_t> indices = skinnedMeshes[0].indices;

	for (uint32_t index = 0; index < skinnedMeshes[0].positions.size(); ++index)
	{
		Vec3f position = skinnedMeshes[0].positions[index];
		Vec3f normal = skinnedMeshes[0].normals[index];
		Vec2f texcoords = skinnedMeshes[0].texCoords[index];
		Vec4f weight = skinnedMeshes[0].weights[index];
		Vec4i joint = skinnedMeshes[0].joints[index];

		vertices.push_back(VertexPositionNormalUvSkin3D(position, normal, texcoords, weight, joint));
	}

	Texture2D* texture = ResourceManager::Get().GetResource<Texture2D>(ResourceManager::Get().Create<Texture2D>("Resource/Texture/Female.png"));
	RUID meshID = ResourceManager::Get().Create<SkinnedMesh>(vertices, indices, false);
	SkinnedMesh* skinnedMesh = ResourceManager::Get().GetResource<SkinnedMesh>(meshID);
	Skeleton skeleton = GLTFLoader::LoadSkeleton(data);
	std::vector<Clip> clips = GLTFLoader::LoadAnimationClip(data);

	GLTFLoader::Free(data);

	int32_t currentClip = 0;

	CrossFadeContoller crossFadeContoller(skeleton);
	crossFadeContoller.Play(&clips[currentClip]);
	crossFadeContoller.Update(0.0f);
	float fadeTime = clips[currentClip].GetDuration();

	RUID skyboxID = ResourceManager::Get().Create<Skybox>(
		"Resource/Skybox/Space_Right.png",
		"Resource/Skybox/Space_Left.png",
		"Resource/Skybox/Space_Top.png",
		"Resource/Skybox/Space_Bottom.png",
		"Resource/Skybox/Space_Front.png",
		"Resource/Skybox/Space_Back.png"
	);
	Skybox* skybox = ResourceManager::Get().GetResource<Skybox>(skyboxID);
	SkyboxPass* skyboxPass = ResourceManager::Get().GetResource<SkyboxPass>(ResourceManager::Get().Create<SkyboxPass>());

	timer.Reset();
	while (!bIsDone)
	{
		InputManager::Get().Tick();
		timer.Tick();

		crossFadeContoller.Update(timer.GetDeltaSeconds());

		fadeTime -= timer.GetDeltaSeconds();
		if (fadeTime < 0.0f)
		{
			uint32_t clip = currentClip;
			while (clip == currentClip)
			{
				clip = MathModule::GenerateRandomInt(0, static_cast<int32_t>(clips.size() - 1));
			}

			currentClip = clip;
			fadeTime = clips[currentClip].GetDuration();
			crossFadeContoller.FadeTo(&clips[currentClip], 1.0f);
		}

		Skeleton& skeleton0 = crossFadeContoller.GetSkeleton();
		skinnedMesh->Skin(&skeleton0, &crossFadeContoller.GetCurrentPose());

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		skyboxPass->Bind();
		skyboxPass->DrawSkybox(view, projection, skybox);
		skyboxPass->Unbind();

		RenderManager::Get().RenderGrid3D(view, projection, -5.0f, 5.0f, 1.0f, -5.0f, +5.0f, 1.0f, Vec4f(1.0f, 1.0f, 1.0f, 1.0f));

		shader->Bind();
		{
			texture->Active(0);

			shader->SetUniform("world", Mat4x4::Identity());
			shader->SetUniform("view", view);
			shader->SetUniform("projection", projection);
			shader->SetUniform("pose", skinnedMesh->GetPosePalette());
			shader->SetUniform("invBindPose", skeleton.GetInvBindPose());

			RenderManager::Get().RenderSkinnedMesh(meshID);
		}
		shader->Unbind();

		const std::vector<VertexPositionNormalUvSkin3D>& vertices = skinnedMesh->GetSkinnedVertices();
		Vec3f minPos = Vec3f(+FLT_MAX, +FLT_MAX, +FLT_MAX);
		Vec3f maxPos = Vec3f(-FLT_MAX, -FLT_MAX, -FLT_MAX);
	
		for (const auto& vertex : vertices)
		{
			minPos.x = MathModule::Min<float>(vertex.position.x, minPos.x);
			minPos.y = MathModule::Min<float>(vertex.position.y, minPos.y);
			minPos.z = MathModule::Min<float>(vertex.position.z, minPos.z);

			maxPos.x = MathModule::Max<float>(vertex.position.x, maxPos.x);
			maxPos.y = MathModule::Max<float>(vertex.position.y, maxPos.y);
			maxPos.z = MathModule::Max<float>(vertex.position.z, maxPos.z);
		}

		Vec3f center = (minPos + maxPos) * 0.5f;
		Vec3f extents = maxPos - minPos;

		RenderManager::Get().RenderCube3D(Mat4x4::Translation(center), view, projection, extents, Vec4f(1.0f, 0.0f, 0.0f, 1.0f));
		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}