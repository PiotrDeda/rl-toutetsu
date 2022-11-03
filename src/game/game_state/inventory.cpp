#include "inventory.h"

Inventory::Inventory(const std::shared_ptr<PlayerStats>& playerStats)
{
	this->playerStats = playerStats;

	for (int i = 0; i < 25; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i, 32 + (i % 5) * 64, 384 + (i / 5) * 64));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(25, 32, 96, Weapon));
	for (int i = 0; i < 6; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i + 26, 96 + (i / 3) * 64, 32 + (i % 3) * 64,
																	static_cast<ItemType>(Helmet + i)));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(32, 0, 0));
}

void Inventory::switchCursorItem(int index)
{
	if (inventorySlots[cursorIndex]->item->type == Blank || inventorySlots[index]->type == General ||
		inventorySlots[index]->type == inventorySlots[cursorIndex]->item->type)
	{
		auto temp = inventorySlots[index]->item;
		inventorySlots[index]->item = inventorySlots[cursorIndex]->item;
		inventorySlots[cursorIndex]->item = temp;
	}

	auto items = std::vector<std::shared_ptr<Item>>(6);
	std::transform(inventorySlots.begin() + 25, inventorySlots.begin() + 31, items.begin(),
				   [](const std::shared_ptr<InventorySlot>& slot) { return slot->item; });
	playerStats->updateStats(items);
}
