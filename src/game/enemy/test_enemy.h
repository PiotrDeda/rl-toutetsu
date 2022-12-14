#pragma once

#include "../../engine/app/app.h"
#include "enemy_data.h"

class TestEnemy : public EnemyData
{
public:
	TestEnemy() { this->sprite = App::get().getSprite("test_unit"); };
};
