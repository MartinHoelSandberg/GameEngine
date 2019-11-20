#pragma once

#include "gepch.h"

#include "GameEngine/Events/Event.h"
#include "GameEngine/Core.h"

namespace GE
{
	struct WindowProps 
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Game Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: title(title), width(width), height(height) {}
	};

	// Interface for Windows desktop systems
	class GE_API Window
	{
		public: 
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() = default;

			virtual void onUpdate() = 0;

			virtual unsigned int getWidth() const = 0;
			virtual unsigned int getHeight() const = 0;

			// Window attributes
			virtual void setEventCallback(const EventCallbackFn& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVSync() const = 0;

			static Window* create(const WindowProps& props = WindowProps());
	};
}



