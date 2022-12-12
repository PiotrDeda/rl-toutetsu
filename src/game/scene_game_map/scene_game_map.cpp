#include "scene_game_map.h"

#include "../game_state/inventory_view.h"
#include "../item/test_item.h"
#include "../item/test_item_2.h"
#include "../loaders/scene_loader.h"
#include "map_objects/pickup_item.h"
#include "map_objects/unit_toutetsu.h"
#include "random_map_generator.h"

SceneGameMap::SceneGameMap() : Scene()
{
	this->map = std::make_shared<Map>(camera, 40);
	camera->setBoundaries(
			-map->tileSize,
			-map->tileSize,
			map->tileSize * map->getSize() + map->tileSize,
			map->tileSize * map->getSize() + map->tileSize
	);

	// Map
	renderables.push_back(map);
	nextLevel();

	// Inventory
	auto inventoryBackgroundObject = createUIObject("ui_equipment_bg", 912, 0);
	auto inventoryView = std::make_shared<InventoryView>(GameState::get().inventory, uiCamera);
	inventoryView->setPosition(912, 0);
	renderables.push_back(inventoryView);
	clickables.push_back(inventoryView);
	GameState::get().inventory->addItem(std::make_shared<TestItem>());
	map->addInteract(std::make_shared<PickupItem>(std::make_shared<TestItem2>()),
					 map->player->x / map->tileSize + 1, map->player->y / map->tileSize);

	// Stats
	auto statsText = std::make_shared<TextObject>("Stats", uiCamera);
	renderables.push_back(statsText);
	statsText->setPosition(941, 237);
	GameState::get().playerStats->addViewSprite(statsText);

	App::get().inputManager.assignInputEventValue(SDLK_s, "MOVE_DOWN");
	App::get().inputManager.assignInputEventValue(SDLK_w, "MOVE_UP");
	App::get().inputManager.assignInputEventValue(SDLK_a, "MOVE_LEFT");
	App::get().inputManager.assignInputEventValue(SDLK_d, "MOVE_RIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_r, "RESET_CAMERA");
	App::get().inputManager.assignInputEventValue(SDLK_e, "CAMERA_MOVE_UPPER_LEFT");
	App::get().inputManager.assignInputEventValue(SDLK_q, "CAMERA_MOVE_LOWER_RIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_f, "SCENE_FIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_g, "REGENERATE_MAP");
}

void SceneGameMap::handleEvent(Event event)
{
	switch (event.type)
	{
		case KeyInput:
			if (event.keyInput.v == "MOVE_DOWN")
				map->movePlayer(0, 1);
			else if (event.keyInput.v == "MOVE_UP")
				map->movePlayer(0, -1);
			else if (event.keyInput.v == "MOVE_LEFT")
				map->movePlayer(-1, 0);
			else if (event.keyInput.v == "MOVE_RIGHT")
				map->movePlayer(1, 0);
			else if (event.keyInput.v == "RESET_CAMERA")
				camera->resetCamera();
			else if (event.keyInput.v == "CAMERA_MOVE_UPPER_LEFT")
				camera->move(-15, -15);
			else if (event.keyInput.v == "CAMERA_MOVE_LOWER_RIGHT")
				camera->move(15, 15);
			else if (event.keyInput.v == "SCENE_FIGHT")
				App::get().sceneManager.setNextScene(SceneId::Fight);
			else if (event.keyInput.v == "REGENERATE_MAP")
				RandomMapGenerator::generateMap(map, RandomMapParameters(), std::random_device{}());
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

void SceneGameMap::nextLevel()
{
	currentLevel++;
	RandomMapGenerator::generateMap(map, RandomMapParameters(), std::random_device{}());
	if (currentLevel == 4)
		map->addInteract(std::make_shared<UnitToutetsu>(), map->exitX, map->exitY);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantParameter"
std::shared_ptr<GameObject> SceneGameMap::createUIObject(const std::string& spriteId, int x, int y)
#pragma clang diagnostic pop
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->setPosition(x, y);
	renderables.push_back(object);
	return object;
}
