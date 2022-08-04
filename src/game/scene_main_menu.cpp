#include "scene_main_menu.h"
#include "../common/app.h"

void SceneMainMenu::enter()
{
	auto sprite = std::make_shared<Sprite>(makeSurface(
			SDL_CreateRGBSurface(0, 32, 32, 32, 0, 0, 0, 0)));
	auto testEntity = std::make_shared<Entity>(App::get().getWindowSurface(), sprite);
	auto testEntity2 = std::make_shared<Entity>(App::get().getWindowSurface(), sprite);
	testEntity2->move(100, 32);
	entities.push_back(testEntity);
	entities.push_back(testEntity2);
}

void SceneMainMenu::doEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			App::get().shutdown();
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_w)
				speed += 1;
			else if (event.key.keysym.sym == SDLK_s)
				speed -= 1;
			break;
		default:
			break;
	}
}

void SceneMainMenu::doLogic()
{
	if (delay++ % 60 == 0)
	{
		for (auto& entity : entities)
		{
			entity->move(entity->x + speed, entity->y + speed);
			if (entity->x > App::get().getWindowSurface()->w || entity->y > App::get().getWindowSurface()->h || entity->x < 0 ||
				entity->y < 0)
				App::get().shutdown();
		}
	}
}
