#include "pkpch.h"
#include "Application.h"
#include "Pekan/Events/ApplicationEvent.h"
#include "Pekan/Log.h"

namespace Pekan {

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
			PK_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			PK_TRACE(e);
		}

		while (true);
	}
}