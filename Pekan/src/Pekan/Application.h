#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Pekan/Events/ApplicationEvent.h"
#include "Window.h"

namespace Pekan {
	
	class PEKAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:

		bool OnWindowCloseEvent(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

