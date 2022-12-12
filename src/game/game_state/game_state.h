#pragma once

#include "../scene_fight/scene_fight.h"
#include "../scene_game_map/scene_game_map.h"
#include "inventory.h"
#include "player_stats.h"

class GameState
{
public:
	SINGLETON(GameState)

	std::shared_ptr<PlayerStats> playerStats = std::make_shared<PlayerStats>();
	std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>(playerStats);
	std::shared_ptr<SceneGameMap> sceneGameMap;
	std::shared_ptr<SceneFight> sceneFight;

private:
	GameState() = default;
};
