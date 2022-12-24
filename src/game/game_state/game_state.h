#pragma once

#include "../enemy/enemy_data.h"
#include "../loaders/scene_loader.h"
#include "../scene_fight/scene_fight.h"
#include "../scene_game_map/scene_game_map.h"
#include "inventory.h"
#include "player_stats.h"

class GameState
{
public:
	SINGLETON(GameState)

	void setSceneGameMap(const std::shared_ptr<SceneGameMap>& scene);
	void setSceneFight(const std::shared_ptr<SceneFight>& scene);
	void nextLevel();
	void startFight(const std::shared_ptr<EnemyData>& enemyData);
	void doPlayerAttack(const std::shared_ptr<ItemData>& spell);
	void doEnemyAttack();

	std::shared_ptr<PlayerStats> playerStats = std::make_shared<PlayerStats>();
	std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>(playerStats);

private:
	GameState() = default;

	std::shared_ptr<SceneGameMap> sceneGameMap;
	std::shared_ptr<SceneFight> sceneFight;
};
