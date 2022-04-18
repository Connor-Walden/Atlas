#include "atlaspch.h"
#include "IndexBuffer.h"

#include "Atlas\Render\Renderer.h"

#include "Platform\OpenGL\Buffer\OpenGLIndexBuffer.h"

namespace Atlas
{
	IndexBuffer* IndexBuffer::Create(uint32_t count, uint32_t* indices)
	{
		switch (Renderer::GetAPI())
		{
		case RenderAPI::API::None:		CORE_ASSERT(false, "RendererAPI None is not supported!"); return nullptr;
		case RenderAPI::API::OpenGL:	return new OpenGLIndexBuffer(count, indices);
		}

		CORE_ASSERT(false, "Unknown RenderAPI...");
		return nullptr;
	}
}