#pragma once

#include <memory>
#include <vector>
#include "../../engine/game_object/text_object.h"
#include "../item/item.h"
#include "stats_set.h"

class PlayerStats
{
public:
	void addViewSprite(const std::shared_ptr<TextObject>& sprite);
	void updateStats(const std::vector<std::shared_ptr<Item>>& items);
	void refreshText();

	StatsSet baseStats = StatsSet(100, 50, 50, 50, 50, 50, 2, 1);
	StatsSet currentStats = baseStats;

private:
	std::vector<std::shared_ptr<TextObject>> sprites;
};
