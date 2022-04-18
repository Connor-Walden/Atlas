#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <string>

namespace Atlas
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadMat4(const std::string& name, const glm::mat4& matrix);

	private:
		uint32_t m_RendererID;
	};
}