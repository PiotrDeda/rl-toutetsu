#pragma once

#include <memory>
#include <vector>
#include "../../engine/game_object/text_object.h"
#include "../item/item.h"
#include "stats_set.h"

class PlayerStats
{
public:
	void addViewSprites(const std::shared_ptr<TextObject>& spriteA, const std::shared_ptr<TextObject>& spriteB);
	void updateStats(const std::vector<std::shared_ptr<Item>>& items);
	void refreshText();

	StatsSet baseStats = StatsSet(100, 50, 50, 50, 50, 2, 1);
	StatsSet currentStats = baseStats;
	int currentHp = currentStats.hp;

private:
	std::vector<std::shared_ptr<TextObject>> spritesA;
	std::vector<std::shared_ptr<TextObject>> spritesB;
};
