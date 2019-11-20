#include "gepch.h"

#include "WindowsWindow.h"
#include "GameEngine/Log.h"

namespace GE
{
	static bool glfwInitialized = false;

	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	GE::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	GE::WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void GE::WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void GE::WindowsWindow::setEventCallback(const EventCallbackFn& callback)
	{
	}

	void GE::WindowsWindow::setVSync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.vsync = enable;
	}

	bool GE::WindowsWindow::isVSync() const
	{
		return data.vsync;
	}

	void GE::WindowsWindow::init(const WindowProps& props)
	{
		data.width = props.width;
		data.height = props.height;
		data.title = props.title;

		GE_CORE_INFO("Creating Window {0} ({1}, {2})", data.title, data.width, data.height);

		if (!glfwInitialized)
		{
			int success = glfwInit();
			GE_CORE_ASSERT(success, "Could not initialize GLFW!");

			glfwInitialized = true;
		}

		window = glfwCreateWindow((int)data.width, (int)data.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		setVSync(true/*vsync*/);
	}

	void GE::WindowsWindow::shutdown()
	{
		glfwDestroyWindow(window);
	}

}

