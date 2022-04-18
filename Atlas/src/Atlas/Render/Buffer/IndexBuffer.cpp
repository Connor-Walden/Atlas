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
		case RendererAPI::None:		CORE_ASSERT(false, "RendererAPI None is not supported!"); return nullptr;
		case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(count, indices);
		}

		CORE_ASSERT(false, "Unknown RendererAPI...");
		return nullptr;
	}
}