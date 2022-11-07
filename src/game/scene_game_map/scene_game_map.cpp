#include "scene_game_map.h"

#include "../game_state/inventory_view.h"
#include "../item/test_item.h"
#include "../item/test_item_2.h"
#include "../loaders/scene_loader.h"
#include "../map_algorithms/fully_random_map.h"

SceneGameMap::SceneGameMap(const std::shared_ptr<GameState>& gameState) : Scene()
{
	this->gameState = gameState;
	camera->setBoundaries(
			-map->tileSize,
			-map->tileSize,
			map->tileSize * map->getSize() + map->tileSize,
			map->tileSize * map->getSize() + map->tileSize
	);

	// Map
	renderables.push_back(map);
	FullyRandomMap::generateMap(map, camera);

	// Test objects
	/*auto testEntity1 = createMapObject("wall", 1, 1);
	auto testEntity2 = createMapObject("wall_torch", 2, 1);
	auto testEntity3 = createMapObject("player", 3, 1);
	auto testEntity4 = createMapObject("wall", 0, 0);
	auto testEntity5 = createMapObject("wall", 10, 10);
	auto testEntity6 = createMapObject("wall_torch", 11, 11);
	auto testEntity7 = createMapObject("wall_torch", 22, 22);
	auto testEntity8 = createMapObject("wall", 23, 23);*/

	// Inventory
	auto inventoryBackgroundObject = createUIObject("ui_equipment_bg", 912, 0);
	auto inventoryView = std::make_shared<InventoryView>(gameState->inventory, uiCamera);
	inventoryView->move(912, 0);
	renderables.push_back(inventoryView);
	clickables.push_back(inventoryView);
	gameState->inventory->addItem(std::make_shared<TestItem>());
	gameState->inventory->addItem(std::make_shared<TestItem2>());

	// Stats
	auto statsText = std::make_shared<TextObject>("Stats", uiCamera);
	renderables.push_back(statsText);
	statsText->move(941, 237);
	gameState->playerStats->addViewSprite(statsText);
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

std::shared_ptr<GameObject> SceneGameMap::createUIObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->move(x, y);
	renderables.push_back(object);
	return object;
}
