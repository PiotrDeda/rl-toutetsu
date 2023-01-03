#pragma once

#include "unit.h"

class BossUnit : public Unit
{
public:
	explicit BossUnit(const std::shared_ptr<EnemyData>& enemyData) : Unit(enemyData) {}

	bool onInteract() override
	{
		GameState::get().startFight(enemyData, true);
		return false;
	}
};
