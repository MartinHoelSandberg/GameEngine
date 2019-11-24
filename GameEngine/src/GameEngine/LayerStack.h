#pragma once
#include "GameEngine/Core.h"
#include "GameEngine/Layer.h"

namespace GE
{
	class GE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer*);
		void pushOverlay(Layer*);
		void popLayer(Layer*);
		void popOverlay(Layer*);

		std::vector<Layer*>::iterator begin()	{ return layers.begin(); }
		std::vector<Layer*>::iterator end()		{ return layers.end(); }
	private:
		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layerInsert;
	};


}