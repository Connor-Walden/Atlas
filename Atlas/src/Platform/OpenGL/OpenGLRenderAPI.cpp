#include "atlaspch.h"
#include "OpenGLRenderAPI.h"

#include <glad/glad.h>

namespace Atlas
{
	void OpenGLRenderAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRenderAPI::Clear(uint32_t flags)
	{
		glClear(flags);
	}

	void OpenGLRenderAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}