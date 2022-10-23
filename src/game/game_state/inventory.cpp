#include "inventory.h"

Inventory::Inventory()
{
	for (int i = 0; i < 30; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i, 32 + (i % 5) * 64, 320 + (i / 5) * 64));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(30, 32, 128));
	for (int i = 0; i < 6; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>(i + 31, 96 + (i / 3) * 64, 64 + (i % 3) * 64));
	inventorySlots.emplace_back(std::make_shared<InventorySlot>(37, 0, 0));
}

void Inventory::switchCursorItem(int index)
{
	auto temp = inventorySlots[index]->item;
	inventorySlots[index]->item = inventorySlots[cursorIndex]->item;
	inventorySlots[cursorIndex]->item = temp;
}
