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

	App::get().inputManager.assignInputEventValue(SDLK_s, "MOVE_DOWN");
	App::get().inputManager.assignInputEventValue(SDLK_w, "MOVE_UP");
	App::get().inputManager.assignInputEventValue(SDLK_a, "MOVE_LEFT");
	App::get().inputManager.assignInputEventValue(SDLK_d, "MOVE_RIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_r, "RESET_CAMERA");
	App::get().inputManager.assignInputEventValue(SDLK_e, "CAMERA_MOVE_UPPER_LEFT");
	App::get().inputManager.assignInputEventValue(SDLK_q, "CAMERA_MOVE_LOWER_RIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_f, "SCENE_FIGHT");
}

void SceneGameMap::handleEvent(Event event)
{
	switch (event.type)
	{
		case KeyInput:
			if (event.keyInput.v == "MOVE_DOWN")
				(*map)[3][1].objects[0]->sprite->setState(0);
			else if (event.keyInput.v == "MOVE_UP")
				(*map)[3][1].objects[0]->sprite->setState(1);
			else if (event.keyInput.v == "MOVE_LEFT")
				(*map)[3][1].objects[0]->sprite->setState(2);
			else if (event.keyInput.v == "MOVE_RIGHT")
				(*map)[3][1].objects[0]->sprite->setState(3);
			else if (event.keyInput.v == "RESET_CAMERA")
				camera->resetCamera();
			else if (event.keyInput.v == "CAMERA_MOVE_UPPER_LEFT")
				camera->move(-15, -15);
			else if (event.keyInput.v == "CAMERA_MOVE_LOWER_RIGHT")
				camera->move(15, 15);
			else if (event.keyInput.v == "SCENE_FIGHT")
				App::get().sceneManager.setNextScene(SceneId::Fight);
			break;
		case MouseWheelInput:
			if (event.mouseWheelInput.y > 0)
				camera->zoomIn();
			else if (event.mouseWheelInput.y < 0)
				camera->zoomOut();
			break;
		case MouseMotion:
			if (event.mouseMotion.rightMouseButton)
				camera->move(-event.mouseMotion.xrel, -event.mouseMotion.yrel);
			break;
		default:
			break;
	}
}

std::shared_ptr<GameObject> SceneGameMap::createUIObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->move(x, y);
	renderables.push_back(object);
	return object;
}
