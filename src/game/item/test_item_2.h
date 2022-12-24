#pragma once

#include "../../engine/app/app.h"
#include "item_data.h"

class TestItem2 : public ItemData
{
public:
	TestItem2()
	{
		this->sprite = App::get().getSprite("test_item_2");
		this->type = Helmet;
	};

	[[nodiscard]] StatsSet applyStatModifiers(const StatsSet& stats) const override
	{
		StatsSet newStats = stats;
		newStats.whiteAttack += 10;
		newStats.blackAttack += 10;
		return newStats;
	}

	void generate() override {}
};
