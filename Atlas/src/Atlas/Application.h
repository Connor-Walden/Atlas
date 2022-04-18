#pragma once

#include "Window.h"
#include "Atlas\Core\Core.h"
#include "Atlas\Layers\LayerStack.h"
#include "Atlas\Events\Event.h"
#include "Atlas\Events\ApplicationEvent.h"

#include "Atlas\ImGui\ImGuiLayer.h"

#include "Atlas\Render\Shader.h"
#include "Atlas\Render\OrthographicCamera.h"
#include "Atlas\Render\Buffer\VertexArray.h"
#include "Atlas\Render\Buffer\VertexBuffer.h"
#include "Atlas\Render\Buffer\IndexBuffer.h"


namespace Atlas
{
	class ATLAS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		uint32_t m_VAO, m_IBO;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_Shader2;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}