#include <Atlas.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Atlas::Layer
{
public:
	ExampleLayer() : Layer("Example"), m_Camera(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f)
	{
		m_VertexArray.reset(Atlas::VertexArray::Create());

		float vertices[7 * 3] =
		{
			-0.5f, -0.5f,  0.0f,  0.3f,  0.8f,  0.3f,  1.0f,
			 0.5f, -0.5f,  0.0f,  0.8f,  0.3f,  0.3f,  1.0f,
			 0.0f,  0.5f,  0.0f,  0.8f,  0.3f,  0.8f,  1.0f
		};
		std::shared_ptr<Atlas::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Atlas::VertexBuffer::Create(sizeof(vertices), vertices));

		{
			Atlas::BufferLayout layout =
			{
				{ Atlas::ShaderDataType::Float3, "a_Position" },
				{ Atlas::ShaderDataType::Float4, "a_Color" }
			};
			vertexBuffer->SetLayout(layout);
		}

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Atlas::IndexBuffer> indexBuffer;
		indexBuffer.reset(Atlas::IndexBuffer::Create(sizeof(indices) / sizeof(uint32_t), indices));

		m_VertexArray->AddVertexBuffer(vertexBuffer);
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Atlas::VertexArray::Create());

		float squareVertices[4 * 3] =
		{
			-0.75f, -0.75f,  0.0f,
			 0.75f, -0.75f,  0.0f,
			 0.75f,  0.75f,  0.0f,
			-0.75f,  0.75f,  0.0f
		};
		std::shared_ptr<Atlas::VertexBuffer> squareVB;
		squareVB.reset(Atlas::VertexBuffer::Create(sizeof(squareVertices), squareVertices));
		squareVB->SetLayout({ { Atlas::ShaderDataType::Float3, "a_Position" } });

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Atlas::IndexBuffer> squareIB;
		squareIB.reset(Atlas::IndexBuffer::Create(sizeof(squareIndices) / sizeof(uint32_t), squareIndices));

		m_SquareVA->AddVertexBuffer(squareVB);
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
			}
		)";

		m_Shader.reset(new Atlas::Shader(vertexSource, fragmentSource));

		std::string vertexSource2 = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSource2 = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(v_Position, 1.0);
			}
		)";

		m_Shader2.reset(new Atlas::Shader(vertexSource2, fragmentSource2));
	}

	void OnUpdate() override
	{
		Atlas::Renderer::Clear(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f), BUFFER_TYPE_COLOR | BUFFER_TYPE_DEPTH);
		
		if (Atlas::Input::IsKeyPressed(ATLAS_KEY_LEFT))		m_CameraPosition.x -= m_CameraSpeed;
		if (Atlas::Input::IsKeyPressed(ATLAS_KEY_RIGHT))	m_CameraPosition.x += m_CameraSpeed;
		if (Atlas::Input::IsKeyPressed(ATLAS_KEY_DOWN))		m_CameraPosition.y -= m_CameraSpeed;
		if (Atlas::Input::IsKeyPressed(ATLAS_KEY_UP))		m_CameraPosition.y += m_CameraSpeed;

		m_Camera.SetPosition(m_CameraPosition);

		Atlas::Renderer::BeginScene(m_Camera);
		
		Atlas::Renderer::Submit(m_Shader2, m_SquareVA);
		Atlas::Renderer::Submit(m_Shader, m_VertexArray);
		
		Atlas::Renderer::EndScene();
	}

	void OnImGuiRender() override
	{

	}

	void OnEvent(Atlas::Event& event) override
	{
		Atlas::EventDispatcher dispatcher(event);
	}

private:
	float m_CameraSpeed = 0.01f;
	glm::vec3 m_CameraPosition = glm::vec3(0.0f);

	std::shared_ptr<Atlas::Shader> m_Shader;
	std::shared_ptr<Atlas::VertexArray> m_VertexArray;
	
	std::shared_ptr<Atlas::Shader> m_Shader2;
	std::shared_ptr<Atlas::VertexArray> m_SquareVA;
	
	Atlas::OrthographicCamera m_Camera;
};

class Sandbox : public Atlas::Application 
{ 
public: 
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	} 
	~Sandbox() { } 
};

Atlas::Application* Atlas::CreateApplication()
{
	return new Sandbox();
}