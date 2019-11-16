#include <GameEngine.h>

class Sandbox : public GE::Application
{
	public: 
		Sandbox() {}
		~Sandbox() {}

};

GE::Application* GE::createApplication()
{
	return new Sandbox();
}


