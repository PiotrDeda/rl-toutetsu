#pragma once

#include "../../engine/app/app.h"
#include "enemy_data.h"

class TestEnemy2 : public EnemyData
{
public:
	TestEnemy2() { this->sprite = App::get().getSprite("test_unit_2"); };
};
