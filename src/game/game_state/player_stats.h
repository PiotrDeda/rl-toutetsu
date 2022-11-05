#pragma once

#include <memory>
#include <vector>
#include "../../engine/game_object/text_object.h"
#include "../item/item.h"
#include "stats_set.h"

class PlayerStats
{
public:
	void addSprite(const std::shared_ptr<TextObject>& sprite);
	void updateStats(const std::vector<std::shared_ptr<Item>>& items);

	StatsSet baseStats = StatsSet(100, 50, 50, 50, 50, 50, 2, 1);
	StatsSet currentStats = baseStats;

private:
	void refreshText();

	std::vector<std::shared_ptr<TextObject>> sprites;
};
