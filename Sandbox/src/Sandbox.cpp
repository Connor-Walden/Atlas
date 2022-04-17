#include <Atlas.h>

class ExampleLayer : public Atlas::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//INFO("ExampleLayer:Update");
	}

	void OnEvent(Atlas::Event& event) override
	{
		//INFO("{0}", event);
		if(Atlas::Input::IsKeyPressed(Atlas::Key::TAB))
			TRACE("Tab key is pressed!");
	}
};

class Sandbox : public Atlas::Application 
{ 
public: 
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Atlas::ImGuiLayer());
	} 
	~Sandbox() { } 
};

Atlas::Application* Atlas::CreateApplication()
{
	return new Sandbox();
}