#pragma once

class PlayerStats
{
public:
	[[nodiscard]] int getHP() const;
	[[nodiscard]] int getMana() const;
	[[nodiscard]] int getWhiteAttack() const;
	[[nodiscard]] int getBlackAttack() const;
	[[nodiscard]] int getWhiteDefense() const;
	[[nodiscard]] int getBlackDefense() const;
	[[nodiscard]] int getCritChance() const;
	[[nodiscard]] int getAgility() const;

private:
	int hp = 100;
	int mana = 50;
	int whiteAttack = 50;
	int blackAttack = 50;
	int whiteDefense = 50;
	int blackDefense = 50;
	int critChance = 2;
	int agility = 1;
};
