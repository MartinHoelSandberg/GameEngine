#pragma once

#include "GameEngine/Core.h"
#include "GameEngine/Window.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/LayerStack.h"

namespace GE
{
	class GE_API Application
	{
		public:
			Application();
			virtual ~Application();

			void run();

			void onEvent(Event&);
			bool onWindowClose(WindowCloseEvent&);

			void pushLayer(Layer*);
			void pushOverlay(Layer*);

		private:
			std::unique_ptr<Window> window;
			LayerStack layerStack;
			bool isRunning = true;
	};

	// Should be defined in the client
	Application* createApplication();
}

