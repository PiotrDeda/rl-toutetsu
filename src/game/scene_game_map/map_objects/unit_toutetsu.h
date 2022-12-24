#pragma once

#include "../../../engine/app/app.h"
#include "../../game_state/game_state.h"
#include "../../item/item_data.h"
#include "map_object.h"

class UnitToutetsu : public MapObject
{
public:
	explicit UnitToutetsu() : MapObject(App::get().getSprite("toutetsu_map")) {}

	bool onInteract() override
	{
		App::get().sceneManager.setNextScene(SceneId::Win);
		return false;
	}
};