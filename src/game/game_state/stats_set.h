#pragma once

class StatsSet
{
public:
	StatsSet(int hp, int mana, int whiteAttack, int blackAttack,
			 int whiteDefense, int blackDefense, int critChance, int agility) :
			hp(hp), mana(mana), whiteAttack(whiteAttack), blackAttack(blackAttack),
			whiteDefense(whiteDefense), blackDefense(blackDefense), critChance(critChance), agility(agility) {}

	int hp;
	int mana;
	int whiteAttack;
	int blackAttack;
	int whiteDefense;
	int blackDefense;
	int critChance;
	int agility;
};