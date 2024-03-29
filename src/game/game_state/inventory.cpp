#include "inventory.h"

#include <algorithm>
#include "game_state.h"

Inventory::Inventory()
{
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(cursorIndex, 0, 0, General));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(equipmentStartIndex, 32, 96, Weapon));
	for (int i = 0; i < 6; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(equipmentStartIndex + 1 + i,
																	96 + (i / 3) * 64,
																	32 + (i % 3) * 64,
																	static_cast<ItemType>(Helmet + i)));
	for (int i = 0; i < spellEndIndex - spellStartIndex + 1; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(spellStartIndex + i,
																	272,
																	40 + i * 80,
																	Spell));
	for (int i = 0; i < mainInventoryEndIndex - mainInventoryStartIndex + 1; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(mainInventoryStartIndex + i,
																	32 + (i % 5) * 64,
																	384 + (i / 5) * 64,
																	General));
}

void Inventory::switchCursorItem(int index, bool equipmentLocked)
{
	if (equipmentLocked && index > cursorIndex && index < mainInventoryStartIndex)
		return;

	if (inventorySlots[cursorIndex]->item->type == Blank || inventorySlots[index]->type == General ||
		inventorySlots[index]->type == inventorySlots[cursorIndex]->item->type)
	{
		auto temp = inventorySlots[index]->item;
		inventorySlots[index]->item = inventorySlots[cursorIndex]->item;
		inventorySlots[cursorIndex]->item = temp;
	}

	refreshStats();
}

void Inventory::addItem(const std::shared_ptr<ItemData>& item)
{
	for (int i = mainInventoryStartIndex; i <= mainInventoryEndIndex; i++)
	{
		if (inventorySlots[i]->item->type == Blank)
		{
			inventorySlots[i]->item = item;
			return;
		}
	}
	inventorySlots[mainInventoryEndIndex]->item = item;
}

void Inventory::refreshStats()
{
	auto items = std::vector<std::shared_ptr<ItemData>>(7);
	std::transform(inventorySlots.begin() + equipmentStartIndex, inventorySlots.begin() + equipmentEndIndex + 1,
				   items.begin(), [](const std::shared_ptr<InventorySlot>& slot) { return slot->item; });
	GameState::get().playerStats->updateStats(items);
}
