#pragma once

#include "../../engine/app/app.h"
#include "enemy.h"

class TestEnemy : public Enemy
{
public:
	TestEnemy() { this->sprite = App::get().getSprite("test_unit"); };
};
