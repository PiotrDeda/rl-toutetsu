#include "scene_game_map.h"
#include "../../common/app.h"

void SceneGameMap::enter()
{
	camera->setBoundaries(-64, -64, 784, 784);

	auto testEntity1 = std::make_shared<GameObject>(App::get().getSprite("wall"), camera);
	map.addObject(testEntity1, 1, 1);

	auto testEntity2 = std::make_shared<GameObject>(App::get().getSprite("wall_torch"), camera);
	map.addObject(testEntity2, 2, 1);

	auto testEntity3 = std::make_shared<GameObject>(App::get().getSprite("player"), camera);
	map.addObject(testEntity3, 3, 1);

	auto testEntity4 = std::make_shared<GameObject>(App::get().getSprite("wall"), camera);
	map.addObject(testEntity4, 0, 0);

	auto testEntity5 = std::make_shared<GameObject>(App::get().getSprite("wall"), camera);
	map.addObject(testEntity5, 10, 10);

	auto testEntity6 = std::make_shared<GameObject>(App::get().getSprite("wall_torch"), camera);
	map.addObject(testEntity6, 11, 11);

	auto testEntity7 = std::make_shared<GameObject>(App::get().getSprite("wall_torch"), camera);
	map.addObject(testEntity7, 22, 22);

	auto testEntity8 = std::make_shared<GameObject>(App::get().getSprite("wall"), camera);
	map.addObject(testEntity8, 23, 23);

	auto uiTestEntity = std::make_shared<GameObject>(App::get().getSprite("ui_test"), uiCamera);
	map.addObject(uiTestEntity, 5, 1);
}

void SceneGameMap::doEvents(SDL_Event event)
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
			else if (event.key.keysym.sym == SDLK_r)
				camera->resetCamera();
			else if (event.key.keysym.sym == SDLK_e)
				camera->move(-15, -15);
			else if (event.key.keysym.sym == SDLK_q)
				camera->move(15, 15);
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				camera->zoomIn();
			else if (event.wheel.y < 0)
				camera->zoomOut();
			break;
		case SDL_MOUSEMOTION:
			if (event.motion.state & SDL_BUTTON_RMASK)
				camera->move(-event.motion.xrel, -event.motion.yrel);
			break;
		default:
			break;
	}
}

void SceneGameMap::doLogic()
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

void SceneGameMap::doRender()
{
	SDL_RenderClear(renderer);
	map.draw();
	SDL_RenderPresent(renderer);
}
