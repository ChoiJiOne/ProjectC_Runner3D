#include <cstdint>
#include <functional>
#include <windows.h>

#include <SDL.h>
#include <glad/glad.h>
#include <cgltf.h>

#include "CrashModule.h"
#include "Transform.h"

#include "Assertion.h"
#include "GameTimer.h"
#include "InputManager.h"
#include "IndexBuffer.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "SDLManager.h"
#include "Texture2D.h"
#include "VertexAttribute.h"

bool bIsDone = false;
GameTimer timer;

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

	std::vector<Vec3f> positions = 
	{ 
		Vec3f(-0.5f, -0.5f, 0.0f),
		Vec3f(+0.5f, -0.5f, 0.0f), 
		Vec3f(+0.0f, +0.5f, 0.0f) 
	};
	VertexAttribute<Vec3f> vertexPosition;
	vertexPosition.Set(positions);

	std::vector<Vec4f> colors = 
	{ 
		Vec4f(1.0f, 0.0f, 0.0f, 1.0f), 
		Vec4f(0.0f, 1.0f, 0.0f, 1.0f), 
		Vec4f(0.0f, 0.0f, 1.0f, 1.0f)
	};
	VertexAttribute<Vec4f> vertexColor;
	vertexColor.Set(colors);

	std::vector<uint32_t> indices = { 0, 1, 2 };
	IndexBuffer indexBuffer;
	indexBuffer.Set(indices);

	RUID shaderID = ResourceManager::Get().Create<Shader>("Shader/Shader.vert", "Shader/Shader.frag");
	Shader* shader = ResourceManager::Get().GetResource<Shader>(shaderID);
	
	timer.Reset();
	while (!bIsDone)
	{
		InputManager::Get().Tick();
		timer.Tick();

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		shader->Bind();
		{
			vertexPosition.Bind(shader->GetVertexAttribute("inPosition"));
			vertexColor.Bind(shader->GetVertexAttribute("inColor"));

			RenderManager::Get().Render(&indexBuffer, ERenderMode::Triangles);

			vertexPosition.Unbind(shader->GetVertexAttribute("inPosition"));
			vertexColor.Unbind(shader->GetVertexAttribute("inColor"));
		}
		shader->Unbind();
		
		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}