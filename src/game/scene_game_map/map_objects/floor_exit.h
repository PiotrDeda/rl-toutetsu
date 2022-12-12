#pragma once

#include "../../../engine/app/app.h"
#include "../../game_state/game_state.h"
#include "../../item/item.h"
#include "map_object.h"

class FloorExit : public MapObject
{
public:
	explicit FloorExit() : MapObject(App::get().getSprite("floor_exit")) {}

	bool onInteract() override
	{
		GameState::get().sceneGameMap->nextLevel();
		return true;
	}
};