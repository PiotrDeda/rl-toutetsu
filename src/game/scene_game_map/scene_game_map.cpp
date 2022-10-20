#include "scene_game_map.h"

#include <utility>
#include "../game_state/inventory_view.h"

SceneGameMap::SceneGameMap(std::shared_ptr<GameState> gameState) : Scene()
{
	this->gameState = std::move(gameState);
	renderables.push_back(map);
	camera->setBoundaries(-64, -64, 784, 784);

	auto testEntity1 = createMapObject("wall", 1, 1);
	auto testEntity2 = createMapObject("wall_torch", 2, 1);
	auto testEntity3 = createMapObject("player", 3, 1);
	auto testEntity4 = createMapObject("wall", 0, 0);
	auto testEntity5 = createMapObject("wall", 10, 10);
	auto testEntity6 = createMapObject("wall_torch", 11, 11);
	auto testEntity7 = createMapObject("wall_torch", 22, 22);
	auto testEntity8 = createMapObject("wall", 23, 23);

	auto uiTestEntity = createUIObject("ui_equipment_bg", 912, 0);

	auto inventoryView = std::make_shared<InventoryView>(this->gameState->inventory, uiCamera);
	inventoryView->move(912, 0);
	renderables.push_back(inventoryView);
}

void SceneGameMap::customEvents(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_s:
					(*map)[3][1].objects[0]->sprite->setState(0);
					break;
				case SDLK_w:
					(*map)[3][1].objects[0]->sprite->setState(1);
					break;
				case SDLK_a:
					(*map)[3][1].objects[0]->sprite->setState(2);
					break;
				case SDLK_d:
					(*map)[3][1].objects[0]->sprite->setState(3);
					break;
				case SDLK_r:
					camera->resetCamera();
					break;
				case SDLK_e:
					camera->move(-15, -15);
					break;
				case SDLK_q:
					camera->move(15, 15);
					break;
				case SDLK_f:
					App::get().sceneManager.setNextScene(SceneId::Fight);
					break;
				default:
					break;
			}
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

void SceneGameMap::customLogic() {}

std::shared_ptr<MapObject> SceneGameMap::createMapObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<MapObject>(App::get().getSprite(spriteId), camera);
	map->addObject(object, x, y);
	return object;
}

std::shared_ptr<GameObject> SceneGameMap::createUIObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->move(x, y);
	renderables.push_back(object);
	return object;
}
