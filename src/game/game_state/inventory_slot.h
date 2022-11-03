#pragma once

#include <memory>
#include "../item/item.h"
#include "../item/blank_item.h"
#include "../../engine/game_object/game_object.h"

class InventorySlot
{
public:
	InventorySlot(int index, int offsetX, int offsetY, ItemType type = General) : index(index), offsetX(offsetX), offsetY(offsetY), type(type) {}

	int index;
	std::shared_ptr<Item> item = std::make_shared<BlankItem>();
	int offsetX;
	int offsetY;
	ItemType type;
};
