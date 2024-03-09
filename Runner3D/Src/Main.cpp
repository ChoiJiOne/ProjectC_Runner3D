#include <cstdint>
#include <functional>
#include <windows.h>

#include "CrashModule.h"
#include "Quat.h"

#include "Assertion.h"
#include "GameTimer.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "SDLManager.h"

bool bIsDone = false;

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	CHECK(CrashModule::RegisterExceptionFilter());
	
	SDLManager::Get().Startup();
	InputManager::Get().Startup();
	ResourceManager::Get().Startup();
	RenderManager::Get().Startup();

	InputManager::Get().AddWindowEventAction(EWindowEvent::CLOSE, [&]() {bIsDone = true; }, true);
	
	Vec2f start(0.0f, 200.0f);
	Vec2f end(200.0f, 0.0f);
	Vec2f position;
	GameTimer timer;

	timer.Reset();
	while (!bIsDone)
	{
		InputManager::Get().Tick();
		timer.Tick();

		position = Vec2f::Slerp(start, end, timer.GetTotalSeconds() / 10.0f);
		
		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		RenderManager::Get().RenderWireframeCircle2D(Vec2f(), 200.0f, Vec4f(0.0f, 0.0f, 1.0f, 1.0f));
		RenderManager::Get().RenderLine2D(Vec2f(0.0f, 0.0f), position, Vec4f(0.0f, 1.0f, 0.0f, 1.0f));

		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}