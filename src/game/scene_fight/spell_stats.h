#pragma once

class SpellStats
{
public:
	SpellStats(int whiteAttack, int blackAttack, int critChance) :
			whiteAttack(whiteAttack), blackAttack(blackAttack), critChance(critChance) {}

	int whiteAttack;
	int blackAttack;
	int critChance;
};
