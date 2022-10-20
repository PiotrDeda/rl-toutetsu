#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "inventory_slot.h"

class Inventory
{
public:
	// 0-29: main inventory
	// 30: weapon
	// 31: helmet
	// 32: body armor
	// 33: boots
	// 34: trinket
	// 35: shield
	// 36: book
	// 37: cursor
	static constexpr int inventorySize = 38;
	static constexpr int cursorIndex = 37;

	Inventory();

	std::vector<std::shared_ptr<InventorySlot>> inventorySlots;
};
