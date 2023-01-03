#pragma once

#include <memory>
#include "enemy_data.h"

class RandomEnemyTemplate
{
public:
	virtual std::shared_ptr<EnemyData> generate() = 0;
};