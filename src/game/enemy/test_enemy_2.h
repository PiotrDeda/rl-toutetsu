#pragma once

#include "../../engine/app/app.h"
#include "enemy.h"

class TestEnemy2 : public Enemy
{
public:
	TestEnemy2() { this->sprite = App::get().getSprite("test_unit_2"); };
};
