#pragma once

#include "inventory.h"
#include "player_stats.h"

class GameState
{
public:
	std::shared_ptr<PlayerStats> playerStats = std::make_shared<PlayerStats>();
	std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>(playerStats);
};
