#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "inventory_slot.h"
#include "player_stats.h"

class Inventory
{
public:
	static constexpr int cursorIndex = 0;
	static constexpr int equipmentStartIndex = 1;
	static constexpr int equipmentEndIndex = 7;
	static constexpr int spellStartIndex = 8;
	static constexpr int spellEndIndex = 11;
	static constexpr int mainInventoryStartIndex = 12;
	static constexpr int mainInventoryEndIndex = 36;

	explicit Inventory(const std::shared_ptr<PlayerStats>& playerStats);

	void switchCursorItem(int index, bool equipmentLocked);
	void addItem(const std::shared_ptr<ItemData>& item);

	std::vector<std::shared_ptr<InventorySlot>> inventorySlots;
	std::shared_ptr<PlayerStats> playerStats;

private:
	void refreshStats();
};
