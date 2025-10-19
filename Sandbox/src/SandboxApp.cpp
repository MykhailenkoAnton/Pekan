

#include <Pekan.h>

class Sandbox : public Pekan::Application
{
public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Pekan::Application* Pekan::CreateApplication()
{
	return new Sandbox();
}