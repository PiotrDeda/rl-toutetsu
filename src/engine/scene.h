#pragma once

#include <SDL_events.h>
#include <vector>
#include "entity.h"

class Scene
{
public:
	Scene();

	virtual void enter();
	virtual void doEvents(SDL_Event event);
	virtual void doLogic();
	void doRender();

	[[nodiscard]] virtual const char* getName() const { return "Scene"; }

	std::vector<std::shared_ptr<Entity>> entities;

private:
	SDL_Renderer* renderer;
};
