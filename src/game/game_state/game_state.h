#pragma once

#include "player_stats.h"
#include "inventory.h"

class GameState
{
public:
	PlayerStats playerStats;
	std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>();
};
