#include <Atlas.h>

class ExampleLayer : public Atlas::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		INFO("ExampleLayer:Update");
	}

	void OnEvent(Atlas::Event& event) override
	{
		INFO("{0}", event);
	}
};

class Sandbox : public Atlas::Application 
{ 
public: 
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	} 
	~Sandbox() { } 
};

Atlas::Application* Atlas::CreateApplication()
{
	return new Sandbox();
}