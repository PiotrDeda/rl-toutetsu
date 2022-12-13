#pragma once

#include <memory>
#include "../../engine/sprite/sprite.h"
#include "../game_state/stats_set.h"

enum ItemType
{
	Blank,
	General,
	Weapon,
	Helmet,
	Armor,
	Boots,
	Trinket,
	Shield,
	Book,
	Spell
};

class Item
{
public:
	[[nodiscard]] virtual StatsSet applyStatModifiers(const StatsSet& stats) const { return stats; }

	std::shared_ptr<Sprite> sprite;
	ItemType type = General;
	int priority = 1;
};
