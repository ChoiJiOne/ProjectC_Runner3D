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
#include "GameTimer.h"
#include "GeometryGenerator.h"
#include "GeometryPass3D.h"
#include "GLTFLoader.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "StaticMesh.h"
#include "SDLManager.h"
#include "Texture2D.h"

#include "Track.h"
#include "TransformTrack.h"

bool bIsDone = false;
GameTimer timer;

Mat4x4 view = Mat4x4::LookAt(Vec3f(0.0f, 5.0f, 5.0f), Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));
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

	RUID geometryPass3D = ResourceManager::Get().Create<GeometryPass3D>();
	GeometryPass3D* geometryPass = ResourceManager::Get().GetResource<GeometryPass3D>(geometryPass3D);

	cgltf_data* data = GLTFLoader::LoadFromFile("Resource/Model/Zombie.gltf");
	Pose resetPose = GLTFLoader::LoadRestPose(data);
	std::vector<Clip> clips = GLTFLoader::LoadAnimationClip(data);
	GLTFLoader::Free(data);
	
	float playbackTime = 0.0f;

	timer.Reset();
	while (!bIsDone)
	{
		InputManager::Get().Tick();
		timer.Tick();

		playbackTime = clips[0].Sample(resetPose, playbackTime + timer.GetDeltaSeconds());

		std::vector<Vec3f> positions(resetPose.GetJointSize());
		for (uint32_t index = 0; index < resetPose.GetJointSize(); ++index)
		{
			if (resetPose.GetParent(index) < 0)
			{
				continue;
			}

			positions.push_back(resetPose.GetGlobalTransform(index).position);
			positions.push_back(resetPose.GetGlobalTransform(resetPose.GetParent(index)).position);
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		
		for (const auto& position : positions)
		{
			geometryPass->DrawSphere3D(Mat4x4::Translation(position), view, projection, 0.01f, Vec4f(1.0f, 0.0f, 0.0f, 1.0f));
		}
		geometryPass->DrawGrid3D(view, projection, -3.0f, 3.0f, 1.0f, -3.0f, +3.0f, 1.0f, Vec4f(1.0f, 1.0f, 1.0f, 1.0f));

		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}