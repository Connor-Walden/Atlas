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
		case RenderAPI::API::None:		CORE_ASSERT(false, "RenderAPI None is not supported!"); return nullptr;
		case RenderAPI::API::OpenGL:	return new OpenGLVertexBuffer(size, vertices);
		}

		CORE_ASSERT(false, "Unknown RenderAPI...");
		return nullptr;
	}
}