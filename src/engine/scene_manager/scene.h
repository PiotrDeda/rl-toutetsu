#pragma once

#include <SDL_events.h>
#include <vector>
#include "../events/event.h"
#include "../game_object/game_object.h"

class Scene
{
public:
	virtual void handleEvent(Event event);
	void doRender();

	[[nodiscard]] virtual const char* getName() const { return "Scene"; }

	std::vector<std::shared_ptr<IRenderable>> renderables;
	std::vector<std::shared_ptr<GameObject>> clickables;

protected:
	Scene();

	RendererPtr renderer;
};
