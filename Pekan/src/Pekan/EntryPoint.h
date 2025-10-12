#pragma once

#ifdef PK_PLARFORM_WINDOWS

extern Pekan::Application* Pekan::CreateApplication();

int main(int argc, char** argv)
{
	printf("Pekan Engine");
	auto app = Pekan::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif