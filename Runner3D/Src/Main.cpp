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
#include "GeometryGenerator.h"
#include "GLTFLoader.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "StaticMesh.h"
#include "SDLManager.h"
#include "Texture2D.h"

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

	cgltf_data* data = GLTFLoader::LoadFromFile("Resource/Model/Zombie.gltf");
	std::vector<GLTFLoader::StaticMeshData> meshDatas = GLTFLoader::LoadStaticMeshData(data);
	GLTFLoader::StaticMeshData& meshData = meshDatas.front();

	std::vector<VertexPositionNormalUv3D> vertices;
	std::vector<uint32_t> indices = meshData.indices;

	for (uint32_t index = 0; index < meshData.positions.size(); ++index)
	{
		Vec3f position = meshData.positions[index];
		Vec3f normal = meshData.normals[index];
		Vec2f texCoords = meshData.texCoords[index];

		vertices.push_back(VertexPositionNormalUv3D(position, normal, texCoords));
	}

	GLTFLoader::Free(data);

	RUID shaderID = ResourceManager::Get().Create<Shader>("Shader/Shader.vert", "Shader/Shader.frag");
	Shader* shader = ResourceManager::Get().GetResource<Shader>(shaderID);

	RUID textureID = ResourceManager::Get().Create<Texture2D>("Resource/Texture/Zombie.png");
	Texture2D* texture = ResourceManager::Get().GetResource<Texture2D>(textureID);

	RUID meshID = ResourceManager::Get().Create<StaticMesh>(vertices, indices);
	StaticMesh* mesh = ResourceManager::Get().GetResource<StaticMesh>(meshID);
	
	timer.Reset();
	while (!bIsDone)
	{
		InputManager::Get().Tick();
		timer.Tick();

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		shader->Bind();
		{
			texture->Active(0);

			shader->SetUniform("world", Mat4x4f::Scale(0.5f, 0.5f, 0.5f));
			shader->SetUniform("view", Mat4x4f::LookAt(Vec3f(3.0f, 3.0f, 3.0f), Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f)));
			shader->SetUniform("projection", Mat4x4f::Perspective(MathModule::ToRadian(45.0f), 1.25f, 0.1f, 100.0f));

			mesh->Bind();
			glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
			mesh->Unbind();
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