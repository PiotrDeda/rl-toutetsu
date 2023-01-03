#include "scene_fight.h"

#include <random>
#include "../game_state/game_state.h"
#include "../game_state/inventory_view.h"
#include "../item/random_item.h"

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
	enemySprite->setPosition(enemyPositionX, enemyPositionY);
	renderables.push_back(enemySprite);

	// Attack animations
	attackAnimationPlayer = std::make_shared<GameObject>(App::get().getSprite("attack_animation_player"), uiCamera);
	attackAnimationPlayer->setPosition(150, 480);
	renderables.push_back(attackAnimationPlayer);

	attackAnimationEnemy = std::make_shared<GameObject>(App::get().getSprite("attack_animation_enemy"), uiCamera);
	attackAnimationEnemy->setPosition(enemyPositionX - 32, enemyPositionY - 64);
	renderables.push_back(attackAnimationEnemy);

	// Spell buttons
	for (int i = 0; i < 5; i++)
	{
		spellButtons.push_back(std::make_shared<SpellButton>(uiCamera));
		spellButtons[i]->setPosition(64 + i * 128, 64);
		spellButtons[i]->enabled = false;
		renderables.push_back(spellButtons[i]);
		clickables.push_back(spellButtons[i]);
	}
	spellButtons[0]->enabled = true;
	spellButtons[0]->spell = std::make_shared<SpellWeapon>()->generate();
}

void SceneFight::setupFight(const std::shared_ptr<EnemyData>& enemyData, const std::shared_ptr<Inventory>& inventory)
{
	enemySprite->sprite = enemyData->fightSprite;
	enemySprite->sprite->setState(2);
	enemySprite->setPosition(enemyPositionX - enemySprite->sprite->getWidth() / 2,
							 enemyPositionY - enemySprite->sprite->getHeight());
	enemyStats = enemyData->stats;
	for (int i = 1; i < 5; i++)
	{
		if (inventory->inventorySlots[Inventory::spellStartIndex + i - 1]->item->type == ItemType::Spell)
		{
			spellButtons[i]->enabled = true;
			spellButtons[i]->spell = inventory->inventorySlots[Inventory::spellStartIndex + i - 1]->item;
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
	if (enemyStats.maxHP <= 0)
	{
		std::mt19937 gen(std::random_device{}());
		std::uniform_int_distribution<> percentageDistr(0, 99);
		if (percentageDistr(gen) < 25)
			GameState::get().inventory->addItem(RandomItem::get().generate(gen));
		App::get().sceneManager.setNextScene(SceneId::GameMap);
		if (bossFight)
			App::get().sceneManager.setNextScene(SceneId::Win);
		return;
	}

	if (playerTurn)
		if (--playerTurnCount <= 0)
			doEnemyTurn();
		else
			doPlayerTurn();
	else if (--enemyTurnCount <= 0)
		doPlayerTurn();
	else
		doEnemyTurn();
}

void SceneFight::doPlayerTurn()
{
	playerTurn = true;
	enemyTurnCount = enemyStats.agility;
	unlockSpells();
}

void SceneFight::doEnemyTurn()
{
	playerTurn = false;
	playerTurnCount = GameState::get().playerStats->currentStats.agility;
	lockSpells();
	GameState::get().doEnemyAttack();
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

void SceneFight::changeTurnCallback(void* object)
{
	static_cast<SceneFight*>(object)->changeTurn();
}
