#pragma once

#include "RenderCommand.h"

namespace Atlas
{
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);
		static void Clear(glm::vec4 color, uint32_t flags);

		inline static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); }
	};
}