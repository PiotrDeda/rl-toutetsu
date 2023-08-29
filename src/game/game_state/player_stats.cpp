#include "player_stats.h"

#include <algorithm>
#include <random>

void PlayerStats::addViewSprites(const std::shared_ptr<TextObject>& spriteA, const std::shared_ptr<TextObject>& spriteB)
{
	spritesA.push_back(spriteA);
	spritesB.push_back(spriteB);
	refreshText();
}

void PlayerStats::updateStats(const std::vector<std::shared_ptr<ItemData>>& items)
{
	std::vector<std::shared_ptr<ItemData>> sortedItems(items.size());
	std::partial_sort_copy(begin(items), end(items), begin(sortedItems), end(sortedItems),
						   [](const std::shared_ptr<ItemData>& a, const std::shared_ptr<ItemData>& b) {
							   return a->priority > b->priority;
						   });
	currentStats = baseStats;
	for (auto& item : sortedItems)
		currentStats = item->applyStatModifiers(currentStats);

	refreshText();
}

void PlayerStats::refreshText()
{
	std::string textA =
			std::to_string(currentHp) + "/" + std::to_string(currentStats.maxHP) + "\n" +
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

void PlayerStats::takeDamage(StatsSet enemyStats)
{
	int totalDamage = calculateDamage(enemyStats.whiteAttack, currentStats.whiteDefense) +
					  calculateDamage(enemyStats.blackAttack, currentStats.blackDefense);

	std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<> percentDistr(0, 99);
	if (percentDistr(gen) < enemyStats.critChance)
		totalDamage *= 2;

	currentHp -= totalDamage;

	refreshText();
}

int PlayerStats::dealDamage(SpellStats spellStats, StatsSet enemyStats) const
{
	int totalDamage = calculateDamage(currentStats.whiteAttack + spellStats.whiteAttack, enemyStats.whiteDefense) +
					  calculateDamage(currentStats.blackAttack + spellStats.blackAttack, enemyStats.blackDefense);

	std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<> percentDistr(0, 99);
	if (percentDistr(gen) < currentStats.critChance + spellStats.critChance)
		totalDamage *= 2;

	return enemyStats.maxHP - totalDamage;
}

int PlayerStats::calculateDamage(int attack, int defense)
{
	if (attack < defense)
		return (attack * attack) / (2 * defense);
	else
		return attack - defense / 2;
}
