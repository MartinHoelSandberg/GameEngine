#pragma once

#include "Event.h"

#include <sstream>

namespace GE
{
	class GE_API MouseMovedEvent : public Event
	{
		public:
			MouseMovedEvent(float x, float y)
				: mouseX(x), mouseY(y) {}

			inline float getX() const { return mouseX; }
			inline float getY() const { return mouseY; }
		 
			std::string toString()
			{
				std::stringstream ss;
				ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved);
			EVENT_CLASS_CATEGORY(Mouse | Input);

		private:
			float mouseX, mouseY;
	};

	// ------------------------------------------------------------ //

	class GE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: offsetX(offsetX), offsetY(offsetY) {}

		inline float getoffsetX() const { return offsetX; }
		inline float getoffsetY() const { return offsetY; }

		std::string toString()
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << offsetX << ", " << offsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(Mouse | Input);

	private:
		float offsetX, offsetY;
	};

	// ------------------------------------------------------------ //

	class GE_API MouseButtonEvent : public Event
	{
		public:
			inline int getMouseButton() const { return button; }

			EVENT_CLASS_CATEGORY(Mouse | Input);
		protected:
			MouseButtonEvent(int button)
				: button(button) {}
			
			int button;
	};

	class GE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
			MouseButtonPressedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string toString()
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class GE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString()
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}