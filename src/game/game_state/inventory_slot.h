#pragma once

#include <memory>
#include "../item/item.h"
#include "../item/blank_item.h"
#include "../../engine/game_object/game_object.h"

class InventorySlot
{
public:
	std::shared_ptr<Item> item = std::make_shared<BlankItem>();
	int offsetX = 0;
	int offsetY = 0;
};
