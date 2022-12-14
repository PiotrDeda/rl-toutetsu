#pragma once

#include "enemy_data.h"
#include "test_enemy.h"
#include "test_enemy_2.h"

class RandomEnemy
{
public:
	static std::shared_ptr<EnemyData> generate(std::mt19937& gen)
	{
		std::uniform_int_distribution<> enemyDistr(0, 1);
		if (enemyDistr(gen) == 0)
			return std::make_shared<TestEnemy>();
		else
			return std::make_shared<TestEnemy2>();
	}
};
