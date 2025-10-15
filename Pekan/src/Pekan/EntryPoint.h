#pragma once

#ifdef PK_PLARFORM_WINDOWS

extern Pekan::Application* Pekan::CreateApplication();

int main(int argc, char** argv)
{	

	Pekan::Log::Init();
	PK_CORE_WARN("Core");
	PK_INFO("App");
	auto app = Pekan::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif