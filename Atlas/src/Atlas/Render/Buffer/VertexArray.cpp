#include "atlaspch.h"
#include "VertexArray.h"

#include "Atlas\Render\Renderer.h"

#include "Platform\OpenGL\Buffer\OpenGLVertexArray.h"

namespace Atlas
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RenderAPI::API::None:		CORE_ASSERT(false, "RenderAPI None is not supported!"); return nullptr;
		case RenderAPI::API::OpenGL:	return new OpenGLVertexArray();
		}

		CORE_ASSERT(false, "Unknown RenderAPI...");
		return nullptr;
	}
}