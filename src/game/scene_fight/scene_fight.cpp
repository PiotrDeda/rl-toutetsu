#include "scene_fight.h"

#include "../game_state/game_state.h"
#include "../game_state/inventory_view.h"
#include "../loaders/scene_loader.h"

SceneFight::SceneFight() : Scene()
{
	// Inventory
	auto inventoryBackgroundObject = createUIObject("equipment_bg", 912, 0);
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
	object->setPosition(x, y);
	renderables.push_back(object);
	return object;
}
