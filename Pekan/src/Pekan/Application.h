#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Pekan/Events/ApplicationEvent.h"

#include "Pekan/LayerStack.h"

#include "Pekan/Layer.h"

namespace Pekan {
	
	class PEKAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:

		bool OnWindowCloseEvent(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

	private:

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

