#pragma once

#include <random>
#include "random_item_template.h"

class EquippableItem : public ItemData
{
public:
	EquippableItem(const char* spriteName, ItemType type, int maxHP, int whiteAttack, int blackAttack, int whiteDefense, int blackDefense, int critChance, int agility)
	{
		this->sprite = App::get().getSprite(spriteName);
		this->type = type;
		this->maxHP = maxHP;
		this->whiteAttack = whiteAttack;
		this->blackAttack = blackAttack;
		this->whiteDefense = whiteDefense;
		this->blackDefense = blackDefense;
		this->critChance = critChance;
		this->agility = agility;
	}

	[[nodiscard]] StatsSet applyStatModifiers(const StatsSet& stats) const override
	{
		StatsSet newStats = stats;
		newStats.maxHP += maxHP;
		newStats.whiteAttack += whiteAttack;
		newStats.blackAttack += blackAttack;
		newStats.whiteDefense += whiteDefense;
		newStats.blackDefense += blackDefense;
		newStats.critChance += critChance;
		newStats.agility += agility;
		return newStats;
	}

	int maxHP = 0;
	int whiteAttack = 0;
	int blackAttack = 0;
	int whiteDefense = 0;
	int blackDefense = 0;
	int critChance = 0;
	int agility = 0;
};

class EquippableItemTemplate : public RandomItemTemplate
{
public:
	std::shared_ptr<ItemData> generate() override
	{
		std::mt19937 gen(std::random_device{}());
		std::normal_distribution<> maxHPDistr(getMaxHPMean(), getMaxHPDeviation());
		std::normal_distribution<> whiteAttackDistr(getWhiteAttackMean(), getWhiteAttackDeviation());
		std::normal_distribution<> blackAttackDistr(getBlackAttackMean(), getBlackAttackDeviation());
		std::normal_distribution<> whiteDefenseDistr(getWhiteDefenseMean(), getWhiteDefenseDeviation());
		std::normal_distribution<> blackDefenseDistr(getBlackDefenseMean(), getBlackDefenseDeviation());
		std::normal_distribution<> critDistr(getCritMean(), getCritDeviation());
		std::normal_distribution<> agilityDistr(getAgilityMean(), getAgilityDeviation());

		int maxHP = std::max(0, static_cast<int>(maxHPDistr(gen)));
		int whiteAttack = std::max(0, static_cast<int>(whiteAttackDistr(gen)));
		int blackAttack = std::max(0, static_cast<int>(blackAttackDistr(gen)));
		int whiteDefense = std::max(0, static_cast<int>(whiteDefenseDistr(gen)));
		int blackDefense = std::max(0, static_cast<int>(blackDefenseDistr(gen)));
		int critChance = std::max(0, static_cast<int>(critDistr(gen)));
		int agility = std::max(0, static_cast<int>(agilityDistr(gen)));

		return std::make_shared<EquippableItem>(getSpriteName(), getType(), maxHP, whiteAttack, blackAttack, whiteDefense, blackDefense, critChance, agility);
	}

protected:
	[[nodiscard]] virtual const char* getSpriteName() const { return ""; }
	[[nodiscard]] virtual ItemType getType() const { return General; }
	[[nodiscard]] virtual int getMaxHPMean() const { return 0; }
	[[nodiscard]] virtual int getMaxHPDeviation() const { return 0; }
	[[nodiscard]] virtual int getWhiteAttackMean() const { return 0; }
	[[nodiscard]] virtual int getWhiteAttackDeviation() const { return 0; }
	[[nodiscard]] virtual int getBlackAttackMean() const { return 0; }
	[[nodiscard]] virtual int getBlackAttackDeviation() const { return 0; }
	[[nodiscard]] virtual int getWhiteDefenseMean() const { return 0; }
	[[nodiscard]] virtual int getWhiteDefenseDeviation() const { return 0; }
	[[nodiscard]] virtual int getBlackDefenseMean() const { return 0; }
	[[nodiscard]] virtual int getBlackDefenseDeviation() const { return 0; }
	[[nodiscard]] virtual int getCritMean() const { return 0; }
	[[nodiscard]] virtual int getCritDeviation() const { return 0; }
	[[nodiscard]] virtual int getAgilityMean() const { return 0; }
	[[nodiscard]] virtual int getAgilityDeviation() const { return 0; }
};

#define DEFINE_EQ(NAME, SPRITE_NAME, TYPE, HPM, HPD, WAM, WAD, BAM, BAD, WDM, WDD, BDM, BDD, CRM, CRD, AGM, AGD) \
class NAME : public EquippableItemTemplate \
{ \
protected: \
    [[nodiscard]] virtual const char* getSpriteName() const override { return #SPRITE_NAME; } \
	[[nodiscard]] virtual ItemType getType() const override { return TYPE; } \
	[[nodiscard]] int getMaxHPMean() const override { return HPM; } \
	[[nodiscard]] int getMaxHPDeviation() const override { return HPD; } \
    [[nodiscard]] int getWhiteAttackMean() const override { return WAM; } \
    [[nodiscard]] int getWhiteAttackDeviation() const override { return WAD; } \
    [[nodiscard]] int getBlackAttackMean() const override { return BAM; } \
    [[nodiscard]] int getBlackAttackDeviation() const override { return BAD; } \
    [[nodiscard]] int getWhiteDefenseMean() const override { return WDM; } \
	[[nodiscard]] int getWhiteDefenseDeviation() const override { return WDD; } \
	[[nodiscard]] int getBlackDefenseMean() const override { return BDM; } \
	[[nodiscard]] int getBlackDefenseDeviation() const override { return BDD; } \
	[[nodiscard]] int getCritMean() const override { return CRM; } \
	[[nodiscard]] int getCritDeviation() const override { return CRD; } \
	[[nodiscard]] int getAgilityMean() const override { return AGM; } \
	[[nodiscard]] int getAgilityDeviation() const override { return AGD; } \
};

//		  Name			Sprite name			Type	HPM	HPD	WAM	WAD	BAM	BAD	WDM	WDD	BDM	BDD	CRM	CRD	AGM	AGD
DEFINE_EQ(WoodenWand,	wooden_wand,		Weapon, 0,	0,	5,	2,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0)
DEFINE_EQ(IronWand,		iron_wand,			Weapon, 0,	0,	30,	4,	0,	0,	0,	0,	0,	0,	2,	1,	0,	0)
DEFINE_EQ(GoldenWand,	golden_wand,		Weapon, 0,	0,	60,	8,	0,	0,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(EnchantedWand,enchanted_wand,		Weapon, 0,	0,	120,16,	0,	0,	0,	0,	0,	0,	4,	1,	0,	0)
DEFINE_EQ(WoodenSword,	wooden_sword,		Weapon, 0,	0,	10,	2,	3,	1,	0,	0,	0,	0,	1,	1,	0,	0)
DEFINE_EQ(IronSword,	iron_sword,			Weapon, 0,	0,	20,	4,	5,	2,	0,	0,	0,	0,	2,	1,	0,	0)
DEFINE_EQ(GoldenSword,	golden_sword,		Weapon, 0,	0,	40,	8,	10,	4,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(EnchantedSword,enchanted_sword,	Weapon, 0,	0,	80,	16,	20,	8,	0,	0,	0,	0,	4,	1,	0,	0)
DEFINE_EQ(WoodenAxe,	wooden_axe,			Weapon, 0,	0,	3,	1,	10,	2,	0,	0,	0,	0,	1,	1,	0,	0)
DEFINE_EQ(IronAxe,		iron_axe,			Weapon, 0,	0,	6,	2,	20,	4,	0,	0,	0,	0,	2,	1,	0,	0)
DEFINE_EQ(GoldenAxe,	golden_axe,			Weapon, 0,	0,	12,	4,	40,	8,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(EnchantedAxe,	enchanted_axe,		Weapon, 0,	0,	24,	8,	80,	16,	0,	0,	0,	0,	4,	1,	0,	0)
DEFINE_EQ(WoodenStaff,	wooden_staff,		Weapon, 0,	0,	0,	0,	15,	2,	0,	0,	0,	0,	1,	1,	0,	0)
DEFINE_EQ(IronStaff,	iron_staff,			Weapon, 0,	0,	0,	0,	30,	4,	0,	0,	0,	0,	2,	1,	0,	0)
DEFINE_EQ(GoldenStaff,	golden_staff,		Weapon, 0,	0,	0,	0,	60,	8,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(EnchantedStaff,enchanted_staff,	Weapon, 0,	0,	0,	0,	120,16,	0,	0,	0,	0,	4,	1,	0,	0)
//		  Name			Sprite name			Type	HPM	HPD	WAM	WAD	BAM	BAD	WDM	WDD	BDM	BDD	CRM	CRD	AGM	AGD
DEFINE_EQ(IronHelmet,	iron_helmet,		Helmet,	0,	0,	0,	0,	0,	0,	10,	2,	10,	2,	0,	0,	0,	0)
DEFINE_EQ(GoldenHelmet,	golden_helmet,		Helmet,	0,	0,	0,	0,	0,	0,	20,	4,	20,	4,	0,	0,	0,	0)
DEFINE_EQ(EnchantedHelmet,enchanted_helmet,	Helmet,	0,	0,	0,	0,	0,	0,	30,	6,	30,	6,	0,	0,	0,	0)
DEFINE_EQ(IronArmor,	iron_armor,			Armor,	0,	0,	0,	0,	0,	0,	10,	2,	10,	2,	0,	0,	0,	0)
DEFINE_EQ(GoldenArmor,	golden_armor,		Armor,	0,	0,	0,	0,	0,	0,	20,	4,	20,	4,	0,	0,	0,	0)
DEFINE_EQ(EnchantedArmor,enchanted_armor,	Armor,	0,	0,	0,	0,	0,	0,	30,	6,	30,	6,	0,	0,	0,	0)
DEFINE_EQ(IronBoots,	iron_boots,			Boots,	0,	0,	0,	0,	0,	0,	10,	2,	10,	2,	0,	0,	1,	0)
DEFINE_EQ(GoldenBoots,	golden_boots,		Boots,	0,	0,	0,	0,	0,	0,	20,	4,	20,	4,	0,	0,	2,	0)
DEFINE_EQ(EnchantedBoots,enchanted_boots,	Boots,	0,	0,	0,	0,	0,	0,	30,	6,	30,	6,	0,	0,	3,	0)
//		  Name			Sprite name			Type	HPM	HPD	WAM	WAD	BAM	BAD	WDM	WDD	BDM	BDD	CRM	CRD	AGM	AGD
DEFINE_EQ(CritPendant,	crit_pendant,		Trinket,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	5,	0,	0,	0)
DEFINE_EQ(HealthPendant,health_pendant,		Trinket,25,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0)
DEFINE_EQ(GreaterHealthPendant,
		  greater_health_pendant,			Trinket,50,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0)
DEFINE_EQ(AgilityPendant,agility_pendant,	Trinket,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0)
//		  Name			Sprite name			Type	HPM	HPD	WAM	WAD	BAM	BAD	WDM	WDD	BDM	BDD	CRM	CRD	AGM	AGD
DEFINE_EQ(WhiteShield,	white_shield,		Shield,	0,	0,	0,	0,	0,	0,	10,	3,	0,	0,	0,	0,	0,	0)
DEFINE_EQ(BlackShield,	black_shield,		Shield,	0,	0,	0,	0,	0,	0,	0,	0,	10,	3,	0,	0,	0,	0)
//		  Name			Sprite name			Type	HPM	HPD	WAM	WAD	BAM	BAD	WDM	WDD	BDM	BDD	CRM	CRD	AGM	AGD
DEFINE_EQ(WhiteBookI,	white_book_i,		Book,	0,	0,	5,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0)
DEFINE_EQ(WhiteBookII,	white_book_ii,		Book,	0,	0,	10,	2,	0,	0,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(WhiteBookIII,	white_book_iii,		Book,	0,	0,	15,	3,	0,	0,	0,	0,	0,	0,	6,	2,	0,	0)
DEFINE_EQ(BlackBookI,	black_book_i,		Book,	0,	0,	0,	0,	5,	1,	0,	0,	0,	0,	0,	0,	0,	0)
DEFINE_EQ(BlackBookII,	black_book_ii,		Book,	0,	0,	0,	0,	10,	2,	0,	0,	0,	0,	3,	1,	0,	0)
DEFINE_EQ(BlackBookIII,	black_book_iii,		Book,	0,	0,	0,	0,	15,	3,	0,	0,	0,	0,	6,	2,	0,	0)
