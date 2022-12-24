#pragma once

#include <memory>
#include "../../engine/game_object/game_object.h"
#include "../item/blank_item.h"

class InventorySlot
{
public:
	InventorySlot(int index, int offsetX, int offsetY, ItemType type) : index(index), offsetX(offsetX), offsetY(offsetY), type(type) {}

	int index;
	std::shared_ptr<ItemData> item = std::make_shared<BlankItem>();
	int offsetX;
	int offsetY;
	ItemType type;
};
