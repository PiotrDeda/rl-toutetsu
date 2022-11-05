#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "inventory_slot.h"
#include "player_stats.h"

class Inventory
{
public:
	static constexpr int cursorIndex = 0;
	static constexpr int weaponIndex = 1;
	static constexpr int helmetIndex = 2;
	static constexpr int bodyArmorIndex = 3;
	static constexpr int bootsIndex = 4;
	static constexpr int trinketIndex = 5;
	static constexpr int shieldIndex = 6;
	static constexpr int bookIndex = 7;
	static constexpr int mainInventoryStartIndex = 8;
	static constexpr int mainInventoryEndIndex = 33;

	explicit Inventory(const std::shared_ptr<PlayerStats>& playerStats);

	void switchCursorItem(int index);

	std::vector<std::shared_ptr<InventorySlot>> inventorySlots;
	std::shared_ptr<PlayerStats> playerStats;
};
