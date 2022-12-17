#include "player_stats.h"

void PlayerStats::addViewSprites(const std::shared_ptr<TextObject>& spriteA, const std::shared_ptr<TextObject>& spriteB)
{
	spritesA.push_back(spriteA);
	spritesB.push_back(spriteB);
	refreshText();
}

void PlayerStats::refreshText()
{
	std::string textA =
			std::to_string(currentHp) + "/" + std::to_string(currentStats.hp) + "\n" +
			std::to_string(currentStats.whiteAttack) + "\n" +
			std::to_string(currentStats.whiteDefense) + "\n" +
			std::to_string(currentStats.critChance);
	const char* cTextA = textA.c_str();

	for (auto& sprite : spritesA)
		sprite->setText(cTextA);

	std::string textB =
			std::to_string(currentStats.blackAttack) + "\n" +
			std::to_string(currentStats.blackDefense) + "\n" +
			std::to_string(currentStats.agility);
	const char* cTextB = textB.c_str();

	for (auto& sprite : spritesB)
		sprite->setText(cTextB);
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
