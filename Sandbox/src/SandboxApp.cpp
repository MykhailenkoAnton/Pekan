

#include <Pekan.h>

#include <string>

class ExampleLayer : public Pekan::Layer
{


public:
	ExampleLayer() : Pekan::Layer("Example") {}

	void OnUpdate() override
	{
		if (Pekan::Input::IsKeyPressed(PK_KEY_TAB))
		{
			PK_TRACE("Key tab is pressed (poll)");
		}
	}

	void OnEvent(Pekan::Event& e) override
	{
		if (e.GetEventType() == Pekan::EventType::KeyPressed)
		{
			const Pekan::KeyPressedEvent& kpe = (Pekan::KeyPressedEvent&) e;
			if (kpe.GetKeyCode() == PK_KEY_TAB)
			{
				PK_TRACE("Key tab is pressed (event)");
			}
		}
	}
};

class Sandbox : public Pekan::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Pekan::Application* Pekan::CreateApplication()
{
	return new Sandbox();
}