#include "atlaspch.h"
#include "VertexBuffer.h"

#include "Atlas\Render\Renderer.h"
#include "Platform\OpenGL\Buffer\OpenGLVertexBuffer.h"

namespace Atlas
{
	VertexBuffer* VertexBuffer::Create(uint32_t size, float* vertices)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:		CORE_ASSERT(false, "RendererAPI None is not supported!"); return nullptr;
		case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(size, vertices);
		}

		CORE_ASSERT(false, "Unknown RendererAPI...");
		return nullptr;
	}
}