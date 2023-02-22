#pragma once

#include "random_enemy_template.h"

#define DEFINE_ENEMY(NAME, DISPLAY_NAME, MAP_SPRITE, FIGHT_SPRITE, MAX_HP, WATK, BATK, WDEF, BDEF, CRIT, AGI) \
class NAME : public RandomEnemyTemplate \
{ \
public: \
	std::shared_ptr<EnemyData> generate() override \
	{ \
		auto enemy = std::make_shared<EnemyData>(); \
        enemy->displayName = DISPLAY_NAME; \
		enemy->mapSprite = App::get().getSprite(#MAP_SPRITE); \
		enemy->fightSprite = App::get().getSprite(#FIGHT_SPRITE); \
		enemy->stats = StatsSet(MAX_HP, WATK, BATK, WDEF, BDEF, CRIT, AGI); \
		return enemy; \
	} \
};


//			 Name			Display name		Map sprite		Fight sprite	HP	WA	BA	WD	BD	CR	AG
DEFINE_ENEMY(GreenSlime,	"Green Slime",		green_slime,	green_slime,	20,	15,	0,	4,	0,	2,	1)
DEFINE_ENEMY(BlueSlime,		"Blue Slime",		blue_slime,		blue_slime,		50,	35,	0,	12,	0,	4,	1)
DEFINE_ENEMY(PurpleSlime,	"Purple Slime",		purple_slime,	purple_slime,	100,55,	0,	25,	0,	6,	1)
DEFINE_ENEMY(FireSlime,		"Fire Slime",		fire_slime,		fire_slime,		150,70,	0,	35,	0,	8,	2)

DEFINE_ENEMY(BlueBeholder,	"Blue Beholder",	blue_beholder,	blue_beholder,	40,	0,	8,	0,	10,	1,	0)
DEFINE_ENEMY(OrangeBeholder,"Orange Beholder",	orange_beholder,orange_beholder,80,	0,	20,	0,	20,	2,	0)
DEFINE_ENEMY(PinkBeholder,	"Pink Beholder",	pink_beholder,	pink_beholder,	130,0,	40,	0,	35,	3,	0)
DEFINE_ENEMY(LavaBeholder,	"Lava Beholder",	lava_beholder,	lava_beholder,	180,0,	60,	0,	50,	4,	2)

DEFINE_ENEMY(ToutetsuUnit,	"Toutetsu",			toutetsu_map,	toutetsu_fight,	400,50,	50,	75,	75,	5,	2)
