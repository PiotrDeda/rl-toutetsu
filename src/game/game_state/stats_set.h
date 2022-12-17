#pragma once

struct StatsSet
{
	StatsSet(int hp, int whiteAttack, int blackAttack,
			 int whiteDefense, int blackDefense, int critChance, int agility) :
			hp(hp), whiteAttack(whiteAttack), blackAttack(blackAttack),
			whiteDefense(whiteDefense), blackDefense(blackDefense), critChance(critChance), agility(agility) {}

	StatsSet() = default;

	int hp;
	int whiteAttack;
	int blackAttack;
	int whiteDefense;
	int blackDefense;
	int critChance;
	int agility;
};
