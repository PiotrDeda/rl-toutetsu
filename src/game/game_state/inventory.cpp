#include "inventory.h"

Inventory::Inventory()
{
	for (int i = 0; i < 25; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i, 32 + (i % 5) * 64, 384 + (i / 5) * 64));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(25, 32, 96));
	for (int i = 0; i < 6; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i + 26, 96 + (i / 3) * 64, 32 + (i % 3) * 64));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(32, 0, 0));
}

void Inventory::switchCursorItem(int index)
{
	auto temp = inventorySlots[index]->item;
	inventorySlots[index]->item = inventorySlots[cursorIndex]->item;
	inventorySlots[cursorIndex]->item = temp;
}
