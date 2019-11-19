#include "Application.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Log.h"

namespace GE
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}


	void Application::run()
	{
		MouseMovedEvent e(100, 200);
		GE_TRACE(e.getName());
		while (true)
		{
		}
	}
}