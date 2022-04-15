#pragma once

#include "Window.h"
#include "Atlas\Core\Core.h"
#include "Atlas\Layers\LayerStack.h"
#include "Atlas\Events\Event.h"
#include "Atlas\Events\ApplicationEvent.h"

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

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}