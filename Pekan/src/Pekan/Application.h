#pragma once

#include "Core.h"

namespace Pekan {
	
	class PEKAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

