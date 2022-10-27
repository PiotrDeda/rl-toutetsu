#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "inventory_slot.h"

class Inventory
{
public:
	// 0-24: main inventory
	// 25: weapon
	// 26: helmet
	// 27: body armor
	// 28: boots
	// 29: trinket
	// 30: shield
	// 31: book
	// 32: cursor
	static constexpr int inventorySize = 33;
	static constexpr int cursorIndex = 32;

	Inventory();

	void switchCursorItem(int index);

	std::vector<std::shared_ptr<InventorySlot>> inventorySlots;
};
