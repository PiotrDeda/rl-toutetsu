#pragma once

#include "../../engine/app/app.h"
#include "enemy_data.h"

class TestEnemy : public EnemyData
{
public:
	TestEnemy()
	{
		this->mapSprite = App::get().getSprite("test_unit_map");
		this->fightSprite = App::get().getSprite("test_unit_fight");
		this->stats = StatsSet(20, 10, 10, 5, 5, 2, 1);
	};
};
