#pragma once

#include <memory>
#include <vector>
#include "../../engine/game_object/text_object.h"
#include "../item/item_data.h"
#include "stats_set.h"

class PlayerStats
{
public:
	void addViewSprites(const std::shared_ptr<TextObject>& spriteA, const std::shared_ptr<TextObject>& spriteB);
	void updateStats(const std::vector<std::shared_ptr<ItemData>>& items);
	void refreshText();
	void takeDamage(StatsSet enemyStats);
	[[nodiscard]] int dealDamage(SpellStats spellStats, StatsSet enemyStats) const;

	StatsSet baseStats = StatsSet(100, 0, 0, 0, 0, 2, 1);
	StatsSet currentStats = baseStats;
	int currentHp = currentStats.maxHP;

private:
	[[nodiscard]] static int calculateDamage(int attack, int defense);

	std::vector<std::shared_ptr<TextObject>> spritesA;
	std::vector<std::shared_ptr<TextObject>> spritesB;
};
