#include "player_stats.h"

int PlayerStats::getHP() const
{
	return hp;
}

int PlayerStats::getMana() const
{
	return mana;
}

int PlayerStats::getWhiteAttack() const
{
	return whiteAttack;
}

int PlayerStats::getBlackAttack() const
{
	return blackAttack;
}

int PlayerStats::getWhiteDefense() const
{
	return whiteDefense;
}

int PlayerStats::getBlackDefense() const
{
	return blackDefense;
}

int PlayerStats::getCritChance() const
{
	return critChance;
}

int PlayerStats::getAgility() const
{
	return agility;
}
