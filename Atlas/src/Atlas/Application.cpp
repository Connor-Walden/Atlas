#include "Application.h"

#include "Events\ApplicationEvent.h"
#include "Log.h"

namespace Atlas
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		TRACE(e);

		while (true);
	}
}