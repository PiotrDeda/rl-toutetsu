#include "scene_fight.h"

#include "../game_state/inventory_view.h"
#include "../loaders/scene_loader.h"

SceneFight::SceneFight(const std::shared_ptr<GameState>& gameState) : Scene()
{
	this->gameState = gameState;

	// Inventory
	auto inventoryBackgroundObject = createUIObject("ui_equipment_bg", 912, 0);
	auto inventoryView = std::make_shared<InventoryView>(gameState->inventory, uiCamera);
	inventoryView->move(912, 0);
	renderables.push_back(inventoryView);
	clickables.push_back(inventoryView);

	// Stats
	auto statsText = std::make_shared<TextObject>("Stats", uiCamera);
	renderables.push_back(statsText);
	statsText->move(941, 237);
	gameState->playerStats->addViewSprite(statsText);

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

std::shared_ptr<GameObject> SceneFight::createUIObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->move(x, y);
	renderables.push_back(object);
	return object;
}
