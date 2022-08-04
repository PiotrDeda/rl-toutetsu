#include "scene.h"
#include "../common/app.h"

Scene::Scene()
{
	this->windowSurface = App::get().getWindowSurface().get();
	this->backgroundColor = SDL_MapRGB(App::get().getWindowSurface()->format, 0xFF, 0xFF, 0xFF);
}

void Scene::enter() {}

void Scene::doEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			App::get().shutdown();
			break;
		default:
			break;
	}
}

void Scene::doLogic() {}

void Scene::doRender()
{
	SDL_FillRect(windowSurface, nullptr, backgroundColor);
	for (auto& entity : entities)
		entity->draw();
}
