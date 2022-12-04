#pragma once

#include "../../../engine/app/app.h"
#include "../../item/item.h"
#include "map_object.h"

class PickupItem : public MapObject
{
public:
	explicit PickupItem(const std::shared_ptr<Item>& item) : MapObject(item->sprite), item(item) {}

	void onInteract(const std::shared_ptr<GameState>& gameState) override
	{
		gameState->inventory->addItem(item);
	}

private:
	std::shared_ptr<Item> item;
};