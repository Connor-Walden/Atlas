#include "atlaspch.h"
#include "Renderer.h"

namespace Atlas
{
    Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
    {
        shader->Bind();
        shader->UploadMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);

        vertexArray->Bind();

        RenderCommand::DrawIndexed(vertexArray);

        vertexArray->Unbind();
        shader->Unbind();
    }

    void Renderer::Clear(glm::vec4 color, uint32_t flags)
    {
        RenderCommand::SetClearColor(color);
        RenderCommand::Clear(flags);
    }
}