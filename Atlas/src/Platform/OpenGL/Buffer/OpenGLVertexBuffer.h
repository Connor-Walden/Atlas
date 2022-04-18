#pragma once

#include "Atlas\Render\Buffer\VertexBuffer.h"

namespace Atlas
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size, float* vertices);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetLayout(const BufferLayout& layout) override
		{
			m_Layout = layout;
		}

		virtual const BufferLayout& GetLayout() const override
		{
			return m_Layout;
		}

	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};
}