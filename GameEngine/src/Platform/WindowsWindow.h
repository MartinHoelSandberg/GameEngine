#pragma once

#include "gepch.h"
#include "GLFW/glfw3.h"
#include "GameEngine/Window.h"

namespace GE
{
	// Interface for Windows desktop systems
	class GE_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void onUpdate() override;

		virtual unsigned int getWidth() const override { return data.width; }
		virtual unsigned int getHeight() const override { return data.height; }

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) override;
		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* window;

		struct WindowData 
		{
			std::string title;
			unsigned int width;
			unsigned int height;

			bool vsync;
			EventCallbackFn callback;
		};

		WindowData data;
	};
}