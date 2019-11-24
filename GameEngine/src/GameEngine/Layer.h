#pragma once
#include "GameEngine/Core.h"
#include "Events/Event.h"

namespace GE
{
	class GE_API Layer
	{
		public:
			Layer(const std::string& name);
			virtual ~Layer();

			virtual void onAttach() {};
			virtual void onDetach() {};
			virtual void onUpdate() {};
			virtual void onEvent(Event& event) {};

		protected:
			std::string debugName;
	};
}

