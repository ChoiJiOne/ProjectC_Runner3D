#include "CrashModule.h"
#include "Transform.h"

#include "Assertion.h"
#include "Camera.h"
#include "Clip.h"
#include "CrossFadeController.h"
#include "EntityManager.h"
#include "GameTimer.h"
#include "GeometryGenerator.h"
#include "GeometryPass3D.h"
#include "GLTFLoader.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "ShadowMap.h"
#include "StaticMesh.h"
#include "SkinnedMesh.h"
#include "Skybox.h"
#include "SkyboxPass.h"
#include "SDLManager.h"
#include "Texture2D.h"

bool bIsDone = false;
GameTimer timer;

Camera* camera = nullptr;

const uint32_t SHADOW_WIDTH = 1024;
const uint32_t SHADOW_HEIGHT = 1024;

Vec3f viewPosition = Vec3f(-10.0f, 10.0f, 0.0f);
Vec3f lightPosition = Vec3f(0.0f, 5.0f, 0.0f);
Vec3f lightDirection = Vec3f(0.0f, -1.0f, 0.0f);
Vec4f lightColor = Vec4f(1.0f, 1.0f, 1.0f, 1.0f);
Mat4x4 lightView = Mat4x4::LookAt(lightPosition, Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 0.0f, 1.0f));
Mat4x4 lightProjection = Mat4x4::Ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 7.5f);

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());
	
	SDLManager::Get().Startup();
	InputManager::Get().Startup();
	ResourceManager::Get().Startup();
	RenderManager::Get().Startup();
	EntityManager::Get().Startup();

	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetMultisampleMode(true);

	InputManager::Get().AddWindowEventAction(EWindowEvent::CLOSE, [&]() {bIsDone = true; }, true);

	camera = EntityManager::Get().CreateEntity<Camera>(
		Vec3f(-10.0f, +5.0f, 0.0f), Vec3f(+1.0f, -0.2f, 0.0f), Vec3f( +0.0f, +1.0f, 0.0f),
		MathModule::ToRadian(45.0f), 1.25f, 0.1f, 100.0f
	);

	std::vector<VertexPositionNormalUv3D> vertices;
	std::vector<uint32_t> indices;

	Shader* shadowPass = ResourceManager::Get().CreateResource<Shader>("Shader/ShadowPass_NoSkinning.vert", "Shader/ShadowPass.frag");
	Shader* lightPass = ResourceManager::Get().CreateResource<Shader>("Shader/LightPass_NoSkinning.vert", "Shader/LightPass.frag");
	Texture2D* texture0 = ResourceManager::Get().CreateResource<Texture2D>("Resource/Texture/earth.png");
	Texture2D* texture1 = ResourceManager::Get().CreateResource<Texture2D>("Resource/Texture/Female.png");
	ShadowMap* shadowMap = ResourceManager::Get().CreateResource<ShadowMap>(SHADOW_WIDTH, SHADOW_HEIGHT);

	GeometryGenerator::CreateSphere(1.0f, 40, vertices, indices);
	StaticMesh* sphere = ResourceManager::Get().CreateResource<StaticMesh>(vertices, indices);

	GeometryGenerator::CreateCube(Vec3f(10.0f, 1.0f, 10.0f), vertices, indices);
	StaticMesh* cube = ResourceManager::Get().CreateResource<StaticMesh>(vertices, indices);

	cgltf_data* data = GLTFLoader::LoadFromFile("Resource/Model/Character.gltf");
	std::vector<GLTFLoader::SkinnedMeshData> skinnedMeshes = GLTFLoader::LoadSkinnedMeshData(data);
	std::vector<VertexPositionNormalUvSkin3D> skinVertices;
	std::vector<uint32_t> skinIndices = skinnedMeshes[0].indices;

	for (uint32_t index = 0; index < skinnedMeshes[0].positions.size(); ++index)
	{
		Vec3f position = skinnedMeshes[0].positions[index];
		Vec3f normal = skinnedMeshes[0].normals[index];
		Vec2f texcoords = skinnedMeshes[0].texCoords[index];
		Vec4f weight = skinnedMeshes[0].weights[index];
		Vec4i joint = skinnedMeshes[0].joints[index];

		skinVertices.push_back(VertexPositionNormalUvSkin3D(position, normal, texcoords, weight, joint));
	}

	SkinnedMesh* skinnedMesh = ResourceManager::Get().CreateResource<SkinnedMesh>(skinVertices, skinIndices, true);
	Skeleton skeleton = GLTFLoader::LoadSkeleton(data);
	std::vector<Clip> clips = GLTFLoader::LoadAnimationClip(data);

	GLTFLoader::Free(data);

	int32_t currentClip = 1;

	CrossFadeContoller crossFadeContoller(skeleton);
	crossFadeContoller.Play(&clips[currentClip]);
	crossFadeContoller.Update(0.0f);

	timer.Reset();
	while (!bIsDone)
	{
		timer.Tick();

		crossFadeContoller.Update(timer.GetDeltaSeconds() / 10.0f);
		skinnedMesh->Skin(&crossFadeContoller.GetSkeleton(), &crossFadeContoller.GetCurrentPose());

		InputManager::Get().Tick();

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		{
			RenderManager::Get().SetViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
			
			shadowMap->Bind();
			shadowMap->Clear();
			shadowPass->Bind();

			shadowPass->SetUniform("view", lightView);
			shadowPass->SetUniform("projection", lightProjection);

			shadowPass->SetUniform("world", Mat4x4::Translation(+0.0f, -0.5f, 0.0f));
			RenderManager::Get().RenderStaticMesh(cube->GetID());

			shadowPass->SetUniform("world", Mat4x4::Identity());
			RenderManager::Get().RenderSkinnedMesh(skinnedMesh->GetID());

			shadowPass->Unbind();
			shadowMap->Unbind();
		}
		{
			RenderManager::Get().SetWindowViewport();

			lightPass->Bind();
			lightPass->SetUniform("view", camera->GetViewMatrix());
			lightPass->SetUniform("projection", camera->GetProjectionMatrix());
			lightPass->SetUniform("lightView", lightView);
			lightPass->SetUniform("lightProjection", lightProjection);
			lightPass->SetUniform("lightDirection", lightDirection);
			lightPass->SetUniform("lightColor", lightColor.x, lightColor.y, lightColor.z);
			lightPass->SetUniform("viewPosition", camera->GetEyePosition());

			texture0->Active(0);
			shadowMap->Active(1);

			lightPass->SetUniform("world", Mat4x4::Translation(+0.0f, -0.5f, 0.0f));
			RenderManager::Get().RenderStaticMesh(cube->GetID());

			texture1->Active(0);
			lightPass->SetUniform("world", Mat4x4::Identity());
			RenderManager::Get().RenderSkinnedMesh(skinnedMesh->GetID());

			lightPass->Unbind();
		}
		RenderManager::Get().EndFrame();
	}
	
	EntityManager::Get().Shutdown();
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}