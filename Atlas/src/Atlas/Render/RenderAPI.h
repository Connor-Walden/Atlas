#pragma once

#include <glm\glm.hpp>

#include "Atlas\Render\Buffer\VertexArray.h"

namespace Atlas
{
	class RenderAPI
	{
	public:
		static enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear(uint32_t flags) = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }

	private:
		static API s_API;
	};
}