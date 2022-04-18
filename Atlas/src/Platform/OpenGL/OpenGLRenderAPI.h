#pragma once

#include "Atlas\Render\RenderAPI.h"

namespace Atlas
{
	class OpenGLRenderAPI : public RenderAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear(uint32_t flags) override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}