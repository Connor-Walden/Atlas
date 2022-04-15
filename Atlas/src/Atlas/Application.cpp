#include "atlaspch.h"

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

		if (e.IsInCategory(EventCategoryApplication))
		{
			TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TRACE(e.ToString());
		}

		while (true);
	}
}