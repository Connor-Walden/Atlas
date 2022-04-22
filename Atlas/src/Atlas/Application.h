#pragma once

#include "Window.h"
#include "Atlas\Core\Core.h"
#include "Atlas\Layers\LayerStack.h"
#include "Atlas\Events\Event.h"
#include "Atlas\Events\ApplicationEvent.h"

#include "Atlas\ImGui\ImGuiLayer.h"

namespace Atlas
{
	class ATLAS_API Application
	{
	public:
		Application();
		virtual ~Application() {}

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		inline static void Stop() { Get().m_Running = false; }
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}