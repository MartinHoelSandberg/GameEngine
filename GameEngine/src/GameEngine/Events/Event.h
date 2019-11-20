#pragma once

#include "GameEngine/Core.h"

namespace GE
{
	/*
		First version of the events systems is going to be blocking.
		Should be implemented as an event bus which is fastly consumed
		by the update function later. 
	*/

	enum class EventType
	{
		None,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None				= 0,
		EventCatApplication	= BIT(0),
		EventCatInput		= BIT(1),
		EventCatKeyboard	= BIT(2),
		EventCatMouse		= BIT(3),
		EventCatMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; } \
								virtual EventType getEventType() const override { return getStaticType(); } \
								virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class GE_API Event
	{
		friend class EventDispatcher;

		public: 
			virtual EventType getEventType() const = 0;
			virtual int getCategoryFlags() const = 0;
			virtual const char* getName() const = 0;
			virtual std::string toString() const { return getName(); }
	
			inline bool isInCategory(const EventCategory& category)
			{
				return getCategoryFlags() & category;
			}

		protected:
			bool handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using eventFn = std::function<bool(T)>; // Todo: Tutorial says "&T", should check if this gets any problems
		
		public:
			EventDispatcher(Event& event)
				: event(event) {}

			template<typename T>
			bool dispatch(eventFn<T> func)
			{
				if (event.getEventType() == T::getStaticEvent())
				{
					event.handled = func(*(T*)&event);
					return true;
				}
				return false;
			}

		private: 
			Event& event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}
}
