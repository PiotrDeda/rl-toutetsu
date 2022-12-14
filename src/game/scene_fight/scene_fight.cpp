#include "scene_fight.h"

#include "../../engine/misc/timer.h"
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
	statsText->setPosition(941, 237);
	renderables.push_back(statsText);
	GameState::get().playerStats->addViewSprite(statsText);

	// Player sprite
	auto playerSprite = std::make_shared<GameObject>(App::get().getSprite("player_fight"), uiCamera);
	playerSprite->setPosition(150, 480);
	playerSprite->sprite->setState(3);
	renderables.push_back(playerSprite);

	// Enemy sprite
	enemySprite = std::make_shared<GameObject>(App::get().getSprite("blank_item"), uiCamera);
	enemySprite->setPosition(750, 480);
	renderables.push_back(enemySprite);

	// Spell buttons
	for (int i = 0; i < 4; i++)
	{
		spellButtons.push_back(std::make_shared<SpellButton>(uiCamera));
		spellButtons[i]->setPosition(64 + i * 128, 64);
		spellButtons[i]->enabled = false;
		renderables.push_back(spellButtons[i]);
		clickables.push_back(spellButtons[i]);
	}

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

void SceneFight::setupFight(const std::shared_ptr<EnemyData>& enemyData, const std::shared_ptr<Inventory>& inventory)
{
	enemySprite->sprite = enemyData->sprite;
	for (int i = 0; i < 4; i++)
	{
		if (inventory->inventorySlots[Inventory::spellStartIndex + i]->item->type == ItemType::Spell)
		{
			spellButtons[i]->enabled = true;
			spellButtons[i]->spell = inventory->inventorySlots[Inventory::spellStartIndex + i]->item;
		}
		else
		{
			spellButtons[i]->enabled = false;
		}
	}
}

void SceneFight::changeTurn()
{
	playersTurn = !playersTurn;

	if (playersTurn)
	{
		for (auto& spellButton : spellButtons)
			spellButton->clickable = true;
	}
	else
	{
		for (auto& spellButton : spellButtons)
			spellButton->clickable = false;
		Timer::startTimer(1000, endEnemyTurn, this);
	}
}

Uint32 SceneFight::endEnemyTurn(Uint32, void* object)
{
	static_cast<SceneFight*>(object)->changeTurn();
	return 0;
}
