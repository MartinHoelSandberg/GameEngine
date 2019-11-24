#include "gepch.h"
#include "Application.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Log.h"

namespace GE
{
	#define BIND_EVENT_FN(func) std::bind(&Application::func, this, std::placeholders::_1)

	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		GE_CORE_TRACE("{0}", event.toString());

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			(*--it)->onEvent(event);
			if (event.handled)
				break;
		}

	}

	void Application::run()
	{
		while (isRunning)
		{
			for (Layer* layer : layerStack)
			{
				layer->onUpdate();
			}

			window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		isRunning = false;
		return true;
	}

	void Application::pushLayer(Layer* layer)
	{
		layerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		layerStack.pushOverlay(overlay);
	}
}