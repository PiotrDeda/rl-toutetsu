#pragma once

struct StatsSet
{
	StatsSet(int maxHP, int whiteAttack, int blackAttack,
			 int whiteDefense, int blackDefense, int critChance, int agility) :
			maxHP(maxHP), whiteAttack(whiteAttack), blackAttack(blackAttack),
			whiteDefense(whiteDefense), blackDefense(blackDefense), critChance(critChance), agility(agility) {}

	StatsSet() = default;

	int maxHP;
	int whiteAttack;
	int blackAttack;
	int whiteDefense;
	int blackDefense;
	int critChance;
	int agility;
};
