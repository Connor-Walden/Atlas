#include "atlaspch.h"
#include "OpenGLIndexBuffer.h"

#include <glad\glad.h>

namespace Atlas
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t count, uint32_t* indices)
		: m_Count(count)
	{
		glCreateBuffers(1, &m_RendererID);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}