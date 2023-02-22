#include "scene_game_map.h"

#include "../enemy/enemies.h"
#include "../game_state/inventory_view.h"
#include "../item/random_item.h"
#include "map_objects/boss_unit.h"
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

	// Level text (init)
	levelText = std::make_shared<TextObject>("Level 1", uiCamera);

	// Map
	renderables.push_back(map);
	nextLevel();

	// Inventory
	auto inventoryBackgroundObject = std::make_shared<GameObject>(App::get().getSprite("equipment_bg"), uiCamera);
	inventoryBackgroundObject->setPosition(912, 0);
	renderables.push_back(inventoryBackgroundObject);
	auto inventoryView = std::make_shared<InventoryView>(GameState::get().inventory, uiCamera);
	inventoryView->setPosition(912, 0);
	renderables.push_back(inventoryView);
	clickables.push_back(inventoryView);
	auto [weapon, spell] = RandomItem::get().generateStartingItems();
	GameState::get().inventory->addItem(weapon);
	GameState::get().inventory->addItem(spell);

	// Stats
	auto statsTextA = std::make_shared<TextObject>("StatsA", uiCamera);
	renderables.push_back(statsTextA);
	statsTextA->setPosition(970, 240);
	auto statsTextB = std::make_shared<TextObject>("StatsB", uiCamera);
	renderables.push_back(statsTextB);
	statsTextB->setPosition(1082, 264);
	GameState::get().playerStats->addViewSprites(statsTextA, statsTextB);

	// Level text
	renderables.push_back(levelText);
	levelText->setPosition(800, 10);

	App::get().inputManager.assignInputEventValue(SDLK_s, "MOVE_DOWN");
	App::get().inputManager.assignInputEventValue(SDLK_w, "MOVE_UP");
	App::get().inputManager.assignInputEventValue(SDLK_a, "MOVE_LEFT");
	App::get().inputManager.assignInputEventValue(SDLK_d, "MOVE_RIGHT");
	App::get().inputManager.assignInputEventValue(SDLK_r, "CENTER_CAMERA");
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
			else if (event.keyInput.v == "CENTER_CAMERA")
				camera->resetCamera();
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
	auto& gameState = GameState::get();
	gameState.currentLevel++;
	gameState.healPlayer();
	RandomMapGenerator::generateMap(map, RandomMapParameters(), std::random_device{}());
	if (gameState.currentLevel == 4)
		map->addInteract(std::make_shared<BossUnit>(ToutetsuUnit().generate()), map->exitX, map->exitY);
	const char* levelBuffer = new char[8];
	sprintf((char*)levelBuffer, "Level %d", gameState.currentLevel);
	levelText->setText(levelBuffer);
}
