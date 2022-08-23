#include "scene_main_menu.h"
#include "../common/app.h"

void SceneMainMenu::enter()
{
	auto testEntity1 = std::make_shared<Entity>(App::get().getSprite("wall"));
	auto testEntity2 = std::make_shared<Entity>(App::get().getSprite("wall_torch"));
	auto testEntity3 = std::make_shared<Entity>(App::get().getSprite("player"));
	testEntity1->move(64, 64);
	testEntity2->move(128, 64);
	testEntity3->move(192, 64);
	entities.push_back(testEntity1);
	entities.push_back(testEntity2);
	entities.push_back(testEntity3);
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
				entities[2]->sprite->setState(0);
			else if (event.key.keysym.sym == SDLK_w)
				entities[2]->sprite->setState(1);
			else if (event.key.keysym.sym == SDLK_a)
				entities[2]->sprite->setState(2);
			else if (event.key.keysym.sym == SDLK_d)
				entities[2]->sprite->setState(3);
			break;
		default:
			break;
	}
}

void SceneMainMenu::doLogic()
{
	/*int w, h;
	SDL_GetWindowSize(App::get().window.get(), &w, &h);
	for (auto& entity : entities)
	{
		entity->move(entity->x + speed, entity->y + speed);
		if (entity->x > w || entity->y > h || entity->x < 0 ||
			entity->y < 0)
			App::get().shutdown();
	}*/
}
