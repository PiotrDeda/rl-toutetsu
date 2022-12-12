#pragma once

#include "../../../engine/app/app.h"
#include "../../game_state/game_state.h"
#include "../../item/item.h"
#include "map_object.h"

class UnitToutetsu : public MapObject
{
public:
	explicit UnitToutetsu() : MapObject(App::get().getSprite("unit_toutetsu")) {}

	bool onInteract() override
	{
		App::get().shutdown();
		return false;
	}
};