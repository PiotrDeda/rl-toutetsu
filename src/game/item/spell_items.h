#pragma once

class SpellItem : public ItemData
{
public:
	SpellItem(const char* spriteName, int whiteAttack, int blackAttack, int critChance)
	{
		this->sprite = App::get().getSprite(spriteName);
		this->type = Spell;
		this->whiteAttack = whiteAttack;
		this->blackAttack = blackAttack;
		this->critChance = critChance;
	}

	[[nodiscard]] SpellStats getSpellStats() const override { return {whiteAttack, blackAttack, critChance}; }

	int whiteAttack = 0;
	int blackAttack = 0;
	int critChance = 0;
};

#define DEFINE_SPELL(NAME, SPRITE_NAME, WHITE_ATTACK, BLACK_ATTACK, CRIT_CHANCE) \
class NAME : public RandomItemTemplate \
{ \
public: \
	std::shared_ptr<ItemData> generate() override { return std::make_shared<SpellItem>(#SPRITE_NAME, WHITE_ATTACK, BLACK_ATTACK, CRIT_CHANCE); } \
};

//			 Name				Sprite name				WAM	BAM	CRI
DEFINE_SPELL(SpellWeapon,		spell_weapon,			0,	0,	0)

DEFINE_SPELL(SpellZap,			spell_zap,				5,	0,	1)
DEFINE_SPELL(SpellBurn,			spell_burn,				2,	2,	1)
DEFINE_SPELL(SpellArrow,		spell_arrow,			0,	5,	1)

DEFINE_SPELL(SpellHolyStrike,	spell_holy_strike,		10,	0,	2)
DEFINE_SPELL(SpellKeystone,		spell_keystone,			4,	4,	2)
DEFINE_SPELL(SpellDarkOrb,		spell_dark_orb,			0,	10,	2)

DEFINE_SPELL(SpellStarShower,	spell_star_shower,		15,	0,	3)
DEFINE_SPELL(SpellWaterGun,		spell_water_gun,		6,	6,	3)
DEFINE_SPELL(SpellPoison,		spell_poison,			0,	15,	3)

DEFINE_SPELL(SpellSunray,		spell_sunray,			20,	0,	4)
DEFINE_SPELL(SpellElementalSeal,spell_elemental_seal,	8,	8,	4)
DEFINE_SPELL(SpellDarkness,		spell_darkness,			0,	20,	4)
