#pragma once

#include <SDL_events.h>
#include <vector>
#include "game_object.h"

class Scene
{
public:
	Scene();

	virtual void enter();
	virtual void doEvents(SDL_Event event);
	virtual void doLogic();
	virtual void doRender();
	void addObject(const std::shared_ptr<GameObject>& object);

	[[nodiscard]] virtual const char* getName() const { return "Scene"; }

	std::vector<std::shared_ptr<GameObject>> gameObjects;

protected:
	SDL_Renderer* renderer;
};
