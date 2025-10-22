#include "pkpch.h"
#include "Application.h"
#include "Pekan/Events/ApplicationEvent.h"
#include "Pekan/Log.h"
#include <GLFW/glfw3.h>

namespace Pekan {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Greate());
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}