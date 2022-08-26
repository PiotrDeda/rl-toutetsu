#include "scene_main_menu.h"
#include "../common/app.h"

void SceneMainMenu::enter()
{
	auto testEntity1 = std::make_shared<GameObject>(App::get().getSprite("wall"));
	map.addObject(testEntity1, 1, 1);

	auto testEntity2 = std::make_shared<GameObject>(App::get().getSprite("wall_torch"));
	map.addObject(testEntity2, 2, 1);

	auto testEntity3 = std::make_shared<GameObject>(App::get().getSprite("player"));
	map.addObject(testEntity3, 3, 1);
}

void SceneMainMenu::doEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			App::get().shutdown();
			break;
		case SDL_KEYDOWN:
			/*if (event.key.keysym.sym == SDLK_w)
				speed += 1;
			else if (event.key.keysym.sym == SDLK_s)
				speed -= 1;*/
			if (event.key.keysym.sym == SDLK_s)
				map[3][1].objects[0]->sprite->setState(0);
			else if (event.key.keysym.sym == SDLK_w)
				map[3][1].objects[0]->sprite->setState(1);
			else if (event.key.keysym.sym == SDLK_a)
				map[3][1].objects[0]->sprite->setState(2);
			else if (event.key.keysym.sym == SDLK_d)
				map[3][1].objects[0]->sprite->setState(3);
			break;
		default:
			break;
	}
}

void SceneMainMenu::doLogic()
{
	/*int w, h;
	SDL_GetWindowSize(App::get().window.get(), &w, &h);
	for (auto& entity : gameObjects)
	{
		entity->move(entity->x + speed, entity->y + speed);
		if (entity->x > w || entity->y > h || entity->x < 0 ||
			entity->y < 0)
			App::get().shutdown();
	}*/
}

void SceneMainMenu::doRender()
{
	SDL_RenderClear(renderer);
	for (auto& entity : gameObjects)
		entity->draw();
	map.draw();
	SDL_RenderPresent(renderer);
}
