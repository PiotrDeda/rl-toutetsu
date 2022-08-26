#include "scene.h"
#include "../common/app.h"

Scene::Scene()
{
	renderer = App::get().renderer.get();
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
	SDL_RenderClear(renderer);
	for (auto& entity : gameObjects)
		entity->draw();
	SDL_RenderPresent(renderer);
}

void Scene::addObject(const std::shared_ptr<GameObject>& object)
{
	gameObjects.push_back(object);
}
