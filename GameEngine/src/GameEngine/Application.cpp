#include "gepch.h"
#include "Application.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Log.h"

namespace GE
{

	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{
	}


	void Application::run()
	{
		while (isRunning)
		{
			window->onUpdate();
		}
	}
}