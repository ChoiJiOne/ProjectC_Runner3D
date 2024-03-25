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

	timer.Reset();
	while (!bIsDone)
	{
		timer.Tick();
		InputManager::Get().Tick();

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}