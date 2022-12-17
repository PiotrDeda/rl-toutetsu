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
	auto statsTextA = std::make_shared<TextObject>("StatsA", uiCamera);
	renderables.push_back(statsTextA);
	statsTextA->setPosition(970, 240);
	auto statsTextB = std::make_shared<TextObject>("StatsB", uiCamera);
	renderables.push_back(statsTextB);
	statsTextB->setPosition(1082, 264);
	GameState::get().playerStats->addViewSprites(statsTextA, statsTextB);

	// Player sprite
	auto playerSprite = std::make_shared<GameObject>(App::get().getSprite("player_fight"), uiCamera);
	playerSprite->setPosition(150, 480);
	playerSprite->sprite->setState(3);
	renderables.push_back(playerSprite);

	// Enemy sprite
	enemySprite = std::make_shared<GameObject>(App::get().getSprite("blank_item"), uiCamera);
	enemySprite->setPosition(700, 480);
	renderables.push_back(enemySprite);

	// Attack animations
	attackAnimationPlayer = std::make_shared<GameObject>(App::get().getSprite("attack_animation_player"), uiCamera);
	attackAnimationPlayer->setPosition(150, 480);
	renderables.push_back(attackAnimationPlayer);

	attackAnimationEnemy = std::make_shared<GameObject>(App::get().getSprite("attack_animation_enemy"), uiCamera);
	attackAnimationEnemy->setPosition(700, 480);
	renderables.push_back(attackAnimationEnemy);

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
	enemySprite->sprite = enemyData->fightSprite;
	enemySprite->sprite->setState(2);
	enemySprite->setPosition(700 - (enemySprite->sprite->getWidth() - 64) / 2, 480 - (enemySprite->sprite->getHeight() - 64) / 2);
	enemyStats = enemyData->stats;
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
	playerTurnCount = GameState::get().playerStats->currentStats.agility;
	enemyTurnCount = enemyStats.agility;
	doPlayerTurn();
}

void SceneFight::changeTurn()
{
	if (GameState::get().playerStats->currentHp <= 0)
	{
		App::get().sceneManager.setNextScene(SceneId::Lose);
		return;
	}
	if (enemyStats.hp <= 0)
	{
		App::get().sceneManager.setNextScene(SceneId::GameMap);
		return;
	}

	if (playerTurn)
		if (--playerTurnCount <= 0)
			doEnemyTurn();
		else
			doPlayerTurn();
	else
		if (--enemyTurnCount <= 0)
			doPlayerTurn();
		else
			doEnemyTurn();
}

void SceneFight::doPlayerTurn()
{
	playerTurn = true;
	enemyTurnCount = enemyStats.agility;
	unlockSpells();
	enemyStats.hp -= 10;
}

void SceneFight::doEnemyTurn()
{
	playerTurn = false;
	playerTurnCount = GameState::get().playerStats->currentStats.agility;
	lockSpells();
	GameState::get().playerStats->currentHp -= 10;
	GameState::get().playerStats->refreshText();
	GameState::get().playAttackAnimationOnPlayer();
}

void SceneFight::lockSpells()
{
	for (auto& spellButton : spellButtons)
		spellButton->clickable = false;
}

void SceneFight::unlockSpells()
{
	for (auto& spellButton : spellButtons)
		spellButton->clickable = true;
}

void SceneFight::endTurn(void* object)
{
	static_cast<SceneFight*>(object)->changeTurn();
}
