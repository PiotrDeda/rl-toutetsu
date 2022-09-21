#pragma once

#include <SDL_events.h>
#include <vector>
#include "../game_object.h"

class Scene
{
public:
	Scene();

	void doEvents(SDL_Event event);
	void doLogic();
	void doRender();

	virtual void customEvents(SDL_Event event);
	virtual void customLogic();
	virtual void customRender();

	[[nodiscard]] virtual const char* getName() const { return "Scene"; }

	std::vector<std::shared_ptr<IRenderable>> renderables;
	std::vector<std::shared_ptr<GameObject>> clickables;

protected:
	std::vector<std::shared_ptr<GameObject>> clickablesQueued;
	SDL_Renderer* renderer;
};
