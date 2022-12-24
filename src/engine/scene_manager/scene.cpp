#include "scene.h"

#include "../app/app.h"

Scene::Scene()
{
	renderer = App::get().renderer;
}

void Scene::handleEvent(Event event) {}

void Scene::doRender()
{
	SDL_SetRenderDrawColor(renderer.get(), 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer.get());
	SDL_SetRenderDrawColor(renderer.get(), 0x2E, 0x30, 0x30, 0xFF);
	SDL_Rect rect = {0, 0, App::defaultWidth, App::defaultHeight};
	SDL_RenderFillRect(renderer.get(), &rect);

	for (auto& renderable : renderables)
		renderable->draw();
	SDL_RenderPresent(renderer.get());
}
