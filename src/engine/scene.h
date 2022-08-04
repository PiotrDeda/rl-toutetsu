#pragma once

#include <SDL_events.h>
#include <vector>
#include "entity.h"

class Scene
{
public:
	explicit Scene();

	virtual void enter();
	virtual void doEvents(SDL_Event event);
	virtual void doLogic();
	void doRender();

	std::vector<std::shared_ptr<Entity>> entities;

private:
	SDL_Surface* windowSurface;
	Uint32 backgroundColor;
};
