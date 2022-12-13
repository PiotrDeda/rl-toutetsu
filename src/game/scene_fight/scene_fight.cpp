#include "scene_fight.h"

#include "../game_state/game_state.h"
#include "../game_state/inventory_view.h"

SceneFight::SceneFight() : Scene()
{
	// Background
	auto background = std::make_shared<GameObject>(App::get().getSprite("fight_bg"), uiCamera);
	renderables.push_back(background);

	// Inventory
	auto inventoryBackgroundObject = std::make_shared<GameObject>(App::get().getSprite("equipment_bg"), uiCamera);
	inventoryBackgroundObject->setPosition(912, 0);
	renderables.push_back(inventoryBackgroundObject);

	auto inventoryView = std::make_shared<InventoryView>(GameState::get().inventory, uiCamera);
	inventoryView->setPosition(912, 0);
	inventoryView->equipmentLocked = true;
	renderables.push_back(inventoryView);
	clickables.push_back(inventoryView);

	// Stats
	auto statsText = std::make_shared<TextObject>("Stats", uiCamera);
	renderables.push_back(statsText);
	statsText->setPosition(941, 237);
	GameState::get().playerStats->addViewSprite(statsText);

	// Player sprite
	auto playerSprite = std::make_shared<GameObject>(App::get().getSprite("player_fight"), uiCamera);
	renderables.push_back(playerSprite);
	playerSprite->setPosition(150, 480);
	playerSprite->sprite->setState(3);

	App::get().inputManager.assignInputEventValue(SDLK_m, "SCENE_GAME_MAP");
}

void SceneFight::handleEvent(Event event)
{
	switch (event.type)
	{
		case KeyInput:
			if (event.keyInput.v == "SCENE_GAME_MAP")
				App::get().sceneManager.setNextScene(SceneId::GameMap);
			break;
		default:
			break;
	}
}

void SceneFight::setEnemy(const std::shared_ptr<Enemy>& enemy)
{

}
