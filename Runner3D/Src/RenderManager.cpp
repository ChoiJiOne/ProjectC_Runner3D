#include <windows.h>

#include <SDL.h>
#include <glad/glad.h>

#include "Mat4x4.h"

#include "Assertion.h"
#include "IndexBuffer.h"
#include "IResource.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "SDLManager.h"
#include "Texture2D.h"
#include "TTFont.h"

RenderManager& RenderManager::Get()
{
	static RenderManager instance;
	return instance;
}

void RenderManager::Startup()
{
	CHECK(!bIsStartup_);
	CHECK(!renderTargetWindow_);

	renderTargetWindow_ = SDLManager::Get().GetMainWindow();
	SDL_Window* window = reinterpret_cast<SDL_Window*>(renderTargetWindow_);

	context_ = SDL_GL_CreateContext(window);
	CHECK(context_ != nullptr);

	SDL_FAILED(SDL_GL_MakeCurrent(window, context_));

	CHECK(gladLoadGLLoader((GLADloadproc)(SDL_GL_GetProcAddress)));

	shaderCache_ = std::map<std::string, RUID>();
	shaderCache_.insert({ "GeometryPass2D", ResourceManager::Get().Create<GeometryPass2D>() });
	shaderCache_.insert({ "SpritePass2D",   ResourceManager::Get().Create<SpritePass2D>()   });
	shaderCache_.insert({ "GlyphPass2D",    ResourceManager::Get().Create<GlyphPass2D>()    });

	bIsStartup_ = true;
}

void RenderManager::Shutdown()
{
	CHECK(bIsStartup_);

	if (context_)
	{
		SDL_GL_DeleteContext(context_);
		context_ = nullptr;
	}

	renderTargetWindow_ = nullptr;
	bIsStartup_ = false;
}

void RenderManager::BeginFrame(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	int32_t width = 0;
	int32_t height = 0;
	GetRenderTargetWindowSize(width, height);
	screenOrtho_ = Mat4x4f::Ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

	glClearColor(red, green, blue, alpha);
	glClearDepth(depth);
	glClearStencil(stencil);

	GL_FAILED(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
}

void RenderManager::EndFrame()
{
	SDL_GL_SwapWindow(reinterpret_cast<SDL_Window*>(renderTargetWindow_));
}

void RenderManager::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
{
	glViewport(x, y, width, height);
}

void RenderManager::SetWindowViewport()
{
	int32_t width = 0;
	int32_t height = 0;
	GetRenderTargetWindowSize(width, height);

	SetViewport(0, 0, width, height);
}

void RenderManager::SetVsyncMode(bool bIsEnable)
{
	SDL_FAILED(SDL_GL_SetSwapInterval(static_cast<int32_t>(bIsEnable)));
}

void RenderManager::SetDepthMode(bool bIsEnable)
{
	if (bIsEnable)
	{
		GL_FAILED(glEnable(GL_DEPTH_TEST));
	}
	else
	{
		GL_FAILED(glDisable(GL_DEPTH_TEST));
	}
}

void RenderManager::SetStencilMode(bool bIsEnable)
{
	if (bIsEnable)
	{
		GL_FAILED(glEnable(GL_STENCIL_TEST));
	}
	else
	{
		GL_FAILED(glDisable(GL_STENCIL_TEST));
	}
}

void RenderManager::SetAlphaBlendMode(bool bIsEnable)
{
	if (bIsEnable)
	{
		GL_FAILED(glEnable(GL_BLEND));
		GL_FAILED(glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO));
	}
	else
	{
		GL_FAILED(glDisable(GL_BLEND));
	}
}

void RenderManager::SetMultisampleMode(bool bIsEnable)
{
	if (bIsEnable)
	{
		GL_FAILED(glEnable(GL_MULTISAMPLE));
	}
	else
	{
		GL_FAILED(glDisable(GL_MULTISAMPLE));
	}
}

void RenderManager::Render(const IndexBuffer* indexBuffer, const ERenderMode& mode)
{
	indexBuffer->Bind();
	GL_FAILED(glDrawElements(static_cast<GLenum>(mode), indexBuffer->GetBufferCount(), GL_UNSIGNED_INT, 0));
	indexBuffer->Unbind();
}

void RenderManager::GetRenderTargetWindowSize(int32_t& outWidth, int32_t& outHeight)
{
	SDL_Window* window = reinterpret_cast<SDL_Window*>(renderTargetWindow_);
	SDL_GetWindowSize(window, &outWidth, &outHeight);
}