#include "gepch.h"

#include "WindowsWindow.h"
#include "GameEngine/Log.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/ApplicationEvent.h"

#include "glad/glad.h"

namespace GE
{
	static bool glfwInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		GE_CORE_ERROR("GLFWError {{0}}: {1}", error, description);
	}

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
		data.callback = callback;
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
			glfwSetErrorCallback(GLFWErrorCallback);
			glfwInitialized = true;
		}

		window = glfwCreateWindow((int)data.width, (int)data.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(window, &data);
		setVSync(true/*vsync*/);

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;

				WindowResizeEvent event(width, height);
				data.callback(event);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.callback(event);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					MouseButtonPressedEvent event(button);
					data.callback(event);
					break;
				}
			}
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.callback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.callback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float) xPos, (float)yPos);
				data.callback(event);
		});
	}

	void GE::WindowsWindow::shutdown()
	{
		glfwDestroyWindow(window);
	}

}

