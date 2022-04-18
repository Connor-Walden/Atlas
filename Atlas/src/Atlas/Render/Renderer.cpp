#include "atlaspch.h"
#include "Renderer.h"

namespace Atlas
{
    void Renderer::BeginScene()
    {

    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
    {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
        vertexArray->Unbind();
    }

    void Renderer::Clear(glm::vec4 color, uint32_t flags)
    {
        RenderCommand::SetClearColor(color);
        RenderCommand::Clear(flags);
    }
}