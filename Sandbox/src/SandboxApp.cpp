

#include <Pekan.h>

#include <string>


class ExampleLayer : public Pekan::Layer
{


public:
	ExampleLayer() : Pekan::Layer("Example") {}

	void OnUpdate() override
	{
		PK_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Pekan::Event& e) override
	{
		PK_TRACE("{0}", e);
	}
};

class Sandbox : public Pekan::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Pekan::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Pekan::Application* Pekan::CreateApplication()
{
	return new Sandbox();
}