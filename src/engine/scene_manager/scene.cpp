#include "scene.h"

#include "../app/app.h"

Scene::Scene()
{
	renderer = App::get().renderer;
}

void Scene::doEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
		{
			int x = App::get().getMouseX();
			int y = App::get().getMouseY();
			if (event.button.button == SDL_BUTTON_LEFT)
				for (auto& clickable : clickables)
					if (clickable->isMouseOver(x, y))
						clickablesQueued.push_back(clickable);
			break;
		}
		default:
			break;
	}

	customEvents(event);
}

void Scene::doLogic()
{
	for (auto& clickable : clickablesQueued)
		clickable->onClick();
	clickablesQueued.clear();

	customLogic();
}

void Scene::doRender()
{
	SDL_RenderClear(renderer.get());
	for (auto& renderable : renderables)
		renderable->draw();
	SDL_RenderPresent(renderer.get());

	customRender();
}

void Scene::customEvents(SDL_Event event) {}

void Scene::customLogic() {}

void Scene::customRender() {}
