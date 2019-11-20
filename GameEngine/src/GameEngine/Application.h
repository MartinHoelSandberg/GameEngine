#pragma once

#include "Core.h"
#include "GameEngine/Window.h"

namespace GE
{
	class GE_API Application
	{
		public:
			Application();
			virtual ~Application();

			void run();

		private:
			std::unique_ptr<Window> window;
			bool isRunning = true;
	};

	// Should be defined in the client
	Application* createApplication();
}

