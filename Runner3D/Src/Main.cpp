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
#include "ShadowMap.h"
#include "StaticMesh.h"
#include "SkinnedMesh.h"
#include "Skybox.h"
#include "SkyboxPass.h"
#include "SDLManager.h"
#include "Texture2D.h"

bool bIsDone = false;
GameTimer timer;

Mat4x4 view = Mat4x4::LookAt(Vec3f(10.0f, 10.0f, 10.0f), Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));
Mat4x4 projection = Mat4x4::Perspective(MathModule::ToRadian(45.0f), 1.25f, 0.1f, 100.0f);

const uint32_t SHADOW_WIDTH = 1024;
const uint32_t SHADOW_HEIGHT = 1024;

Vec3f viewPosition = Vec3f(10.0f, 10.0f, 10.0f);
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

	RenderManager::Get().SetAlphaBlendMode(true);
	RenderManager::Get().SetDepthMode(true);
	RenderManager::Get().SetMultisampleMode(true);

	InputManager::Get().AddWindowEventAction(EWindowEvent::CLOSE, [&]() {bIsDone = true; }, true);

	std::vector<VertexPositionNormalUv3D> vertices;
	std::vector<uint32_t> indices;

	Shader* shadowPass = ResourceManager::Get().CreateResource<Shader>("Shader/ShadowPass_NoSkinning.vert", "Shader/ShadowPass.frag");
	Shader* lightPass = ResourceManager::Get().CreateResource<Shader>("Shader/LightPass_NoSkinning.vert", "Shader/LightPass.frag");
	Texture2D* texture = ResourceManager::Get().CreateResource<Texture2D>("Resource/Texture/earth.png");
	ShadowMap* shadowMap = ResourceManager::Get().CreateResource<ShadowMap>(SHADOW_WIDTH, SHADOW_HEIGHT);

	GeometryGenerator::CreateSphere(1.0f, 40, vertices, indices);
	StaticMesh* sphere = ResourceManager::Get().CreateResource<StaticMesh>(vertices, indices);

	GeometryGenerator::CreateCube(Vec3f(10.0f, 1.0f, 10.0f), vertices, indices);
	StaticMesh* cube = ResourceManager::Get().CreateResource<StaticMesh>(vertices, indices);

	timer.Reset();
	while (!bIsDone)
	{
		timer.Tick();
		InputManager::Get().Tick();

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		{
			RenderManager::Get().SetViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
			
			shadowPass->Bind();
			shadowMap->Bind();
			shadowMap->Clear();

			shadowPass->SetUniform("view", lightView);
			shadowPass->SetUniform("projection", lightProjection);

			shadowPass->SetUniform("world", Mat4x4::Translation(-2.0f, +1.0f, +0.0f));
			RenderManager::Get().RenderStaticMesh(sphere->GetID());

			shadowPass->SetUniform("world", Mat4x4::Translation(+2.0f, +1.0f, +0.0f));
			RenderManager::Get().RenderStaticMesh(sphere->GetID());

			shadowPass->SetUniform("world", Mat4x4::Translation(+0.0f, -0.5f, 0.0f));
			RenderManager::Get().RenderStaticMesh(cube->GetID());

			shadowMap->Unbind();
			shadowPass->Unbind();
		}
		{
			RenderManager::Get().SetWindowViewport();

			lightPass->Bind();
			lightPass->SetUniform("view", view);
			lightPass->SetUniform("projection", projection);
			lightPass->SetUniform("lightView", lightView);
			lightPass->SetUniform("lightProjection", lightProjection);
			lightPass->SetUniform("lightDirection", lightDirection);
			lightPass->SetUniform("lightColor", lightColor.x, lightColor.y, lightColor.z);
			lightPass->SetUniform("viewPosition", viewPosition);

			texture->Active(0);
			shadowMap->Active(1);

			lightPass->SetUniform("world", Mat4x4::Translation(-2.0f, +1.0f, +0.0f));
			RenderManager::Get().RenderStaticMesh(sphere->GetID());

			lightPass->SetUniform("world", Mat4x4::Translation(+2.0f, +1.0f, +0.0f));
			RenderManager::Get().RenderStaticMesh(sphere->GetID());

			lightPass->SetUniform("world", Mat4x4::Translation(+0.0f, -0.5f, 0.0f));
			RenderManager::Get().RenderStaticMesh(cube->GetID());

			lightPass->Unbind();
		}
		RenderManager::Get().EndFrame();
	}
	
	ResourceManager::Get().Shutdown();
	RenderManager::Get().Shutdown();
	InputManager::Get().Shutdown();
	SDLManager::Get().Shutdown();

	return 0;
}