#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../enemy/enemy_data.h"
#include "../game_state/inventory.h"
#include "spell_button.h"

class SceneFight : public Scene
{
public:
	const static int enemyPositionX = 732;
	const static int enemyPositionY = 544;

	SceneFight();

	void setupFight(const std::shared_ptr<EnemyData>& enemyData, const std::shared_ptr<Inventory>& inventory);
	void changeTurn();
	void doPlayerTurn();
	void doEnemyTurn();
	void lockSpells();
	void unlockSpells();

	static void changeTurnCallback(void* object);

	[[nodiscard]] const char* getName() const override { return "SceneFight"; }

	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
	std::vector<std::shared_ptr<SpellButton>> spellButtons;
	std::shared_ptr<GameObject> enemySprite;
	StatsSet enemyStats{};
	std::shared_ptr<GameObject> attackAnimationPlayer;
	std::shared_ptr<GameObject> attackAnimationEnemy;
	bool playerTurn = true;
	int playerTurnCount = 0;
	int enemyTurnCount = 0;
	bool bossFight = false;
};
