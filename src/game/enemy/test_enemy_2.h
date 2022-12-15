#pragma once

#include "../../engine/app/app.h"
#include "enemy_data.h"

class TestEnemy2 : public EnemyData
{
public:
	TestEnemy2()
	{
		this->mapSprite = App::get().getSprite("test_unit_2_map");
		this->fightSprite = App::get().getSprite("test_unit_2_fight");
		this->stats = StatsSet(50, 0, 10, 0, 15, 5, 5, 2);
	};
};
