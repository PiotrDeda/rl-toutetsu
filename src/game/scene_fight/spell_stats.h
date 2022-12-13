#pragma once

class SpellStats
{
public:
	SpellStats(int manaCost, int attackCount, int whiteAttack, int blackAttack, int critChance) :
			manaCost(manaCost), attackCount(attackCount),
			whiteAttack(whiteAttack), blackAttack(blackAttack), critChance(critChance) {}

	int manaCost;
	int attackCount;
	int whiteAttack;
	int blackAttack;
	int critChance;
};
