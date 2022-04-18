#pragma once

#include "RenderAPI.h"

namespace Atlas
{
	class RenderCommand
	{
	public:
		inline static void SetClearColor(const glm::vec4& color) { s_RenderAPI->SetClearColor(color); }
		inline static void Clear(uint32_t flags) { s_RenderAPI->Clear(flags); }
		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) { s_RenderAPI->DrawIndexed(vertexArray); }

	private:
		static RenderAPI* s_RenderAPI;
	};
}