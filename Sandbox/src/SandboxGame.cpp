#include <GameEngine.h>


class ExampleLayer : public GE::Layer
{
	public:
		ExampleLayer() : 
			Layer("ExampleLayer") 
		{}
		
		~ExampleLayer() 
		{}

		void onUpdate() override
		{
			GE_INFO("Layer Called Update!");
		}

		void onEvent(GE::Event& event) override
		{
			GE_TRACE("{0}", event.toString());
		}
};


class Sandbox : public GE::Application
{
	public: 
		Sandbox() 
		{
			pushLayer(new ExampleLayer());
		}

		~Sandbox() {}

};

GE::Application* GE::createApplication()
{
	return new Sandbox();
}


