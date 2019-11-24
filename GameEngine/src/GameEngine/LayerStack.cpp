#include "gepch.h"
#include "LayerStack.h"

GE::LayerStack::LayerStack()
{
	layerInsert = layers.begin();
}

GE::LayerStack::~LayerStack()
{
	for (Layer* layer : layers)
		delete layer;
}

void GE::LayerStack::pushLayer(Layer* layer)
{
	layerInsert = layers.emplace(layerInsert, layer);
}

void GE::LayerStack::pushOverlay(Layer* overlay)
{
	layers.emplace_back(overlay);
}

void GE::LayerStack::popLayer(Layer* layer)
{
	auto it = std::find(layers.begin(), layers.end(), layer);
	if (it != layers.end())
	{
		layers.erase(it);
		it--;
	}
}


void GE::LayerStack::popOverlay(Layer* overlay)
{
	auto it = std::find(layers.begin(), layers.end(), overlay);
	if (it != layers.end())
	{
		layers.erase(it);
	}
}
