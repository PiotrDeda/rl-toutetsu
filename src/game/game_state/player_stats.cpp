#include "player_stats.h"

void PlayerStats::addSprite(const std::shared_ptr<TextObject>& sprite)
{
	sprites.push_back(sprite);
	refreshText();
}

void PlayerStats::refreshText()
{
	std::string text =
			"HP:   " + std::to_string(currentStats.hp) +
			" MANA: " + std::to_string(currentStats.mana) + "\n" +
			"WATK: " + std::to_string(currentStats.whiteAttack) +
			"  BATK: " + std::to_string(currentStats.blackAttack) + "\n" +
			"WDEF: " + std::to_string(currentStats.whiteDefense) +
			"  BDEF: " + std::to_string(currentStats.blackDefense) + "\n" +
			"CRIT: " + std::to_string(currentStats.critChance) +
			"   AGI:  " + std::to_string(currentStats.agility);
	const char* cText = text.c_str();

	for (auto& sprite : sprites)
		sprite->setText(cText);
}

void PlayerStats::updateStats(const std::vector<std::shared_ptr<Item>>& items)
{
	std::vector<std::shared_ptr<Item>> sortedItems(items.size());
	std::partial_sort_copy(begin(items), end(items), begin(sortedItems), end(sortedItems),
						   [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
							   return a->priority > b->priority;
						   });
	currentStats = baseStats;
	for (auto& item : sortedItems)
		currentStats = item->applyStatModifiers(currentStats);

	refreshText();
}
