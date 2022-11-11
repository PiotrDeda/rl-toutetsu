#include "scene.h"

#include "../app/app.h"

Scene::Scene()
{
	renderer = App::get().renderer;
}

void Scene::handleEvent(Event event) {}

void Scene::doRender()
{
	SDL_RenderClear(renderer.get());
	for (auto& renderable : renderables)
		renderable->draw();
	SDL_RenderPresent(renderer.get());

	customRender();
}

void Scene::customRender() {}
