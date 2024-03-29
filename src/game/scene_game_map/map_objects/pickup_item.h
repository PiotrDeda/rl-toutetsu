#pragma once

#include "../../../engine/app/app.h"
#include "../../game_state/game_state.h"
#include "../../item/item_data.h"
#include "map_object.h"

class PickupItem : public MapObject
{
public:
	explicit PickupItem(const std::shared_ptr<ItemData>& item) : MapObject(item->sprite), item(item) {}

	bool onInteract() override
	{
		GameState::get().inventory->addItem(item);
		return false;
	}

private:
	std::shared_ptr<ItemData> item;
};
