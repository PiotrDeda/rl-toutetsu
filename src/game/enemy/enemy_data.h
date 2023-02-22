#pragma once

#include <memory>
#include "../../engine/sprite/sprite.h"
#include "../game_state/stats_set.h"

class EnemyData
{
public:
	const char* displayName;
	std::shared_ptr<Sprite> mapSprite;
	std::shared_ptr<Sprite> fightSprite;
	StatsSet stats{};
};
