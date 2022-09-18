#include "scene.h"
#include "../../common/app.h"

Scene::Scene()
{
	renderer = App::get().renderer.get();
}

void Scene::enter() {}

void Scene::doEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (event.button.button == SDL_BUTTON_LEFT)
				for (auto& clickable : clickables)
					if (clickable->isMouseOver(x, y))
						clickablesQueued.push_back(clickable);
			break;
		case SDL_QUIT:
			App::get().shutdown();
			break;
		default:
			break;
	}
}

void Scene::doLogic()
{
	for (auto& clickable : clickablesQueued)
		clickable->onClick();
	clickablesQueued.clear();
}

void Scene::doRender()
{
	SDL_RenderClear(renderer);
	for (auto& renderable : renderables)
		renderable->draw();
	SDL_RenderPresent(renderer);
}
