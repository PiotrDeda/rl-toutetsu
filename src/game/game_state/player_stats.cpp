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

void PlayerStats::addSprite(const std::shared_ptr<TextObject>& sprite)
{
	sprites.push_back(sprite);
}

void PlayerStats::refreshText()
{
	std::string text = 	"HP:   " + std::to_string(getHP()) 				+ " MANA: " + std::to_string(getMana())			+ "\n" +
						"WATK: " + std::to_string(getWhiteAttack()) 	+ "  BATK: " + std::to_string(getBlackAttack()) 	+ "\n" +
						"WDEF: " + std::to_string(getWhiteDefense()) 	+ "  BDEF: " + std::to_string(getBlackDefense()) + "\n" +
						"CRIT: " + std::to_string(getCritChance())		+ "   AGI:  " + std::to_string(getAgility());
	const char* cText = text.c_str();

	for (auto& sprite : sprites)
	{
		sprite->setText(cText);
	}
}
