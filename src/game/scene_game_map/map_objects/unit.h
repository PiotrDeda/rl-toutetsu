#pragma once

#include "../../enemy/enemy_data.h"
#include "../../game_state/game_state.h"
#include "../../loaders/scene_loader.h"
#include "map_object.h"

class Unit : public MapObject
{
public:
	explicit Unit(const std::shared_ptr<EnemyData>& enemyData) : MapObject(enemyData->mapSprite), enemyData(enemyData) {}

	bool onInteract() override
	{
		GameState::get().startFight(enemyData);
		return false;
	}

private:
	std::shared_ptr<EnemyData> enemyData;
};
