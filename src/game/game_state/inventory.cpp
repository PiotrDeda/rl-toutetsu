#include "inventory.h"

Inventory::Inventory()
{
	for (int i = 0; i < inventorySize; i++)
		inventorySlots.emplace_back(std::make_shared<InventorySlot>());

	for (int i = 0; i < 30; i++)
	{
		inventorySlots[i]->offsetX = 32 + (i % 5) * 64;
		inventorySlots[i]->offsetY = 320 + (i / 5) * 64;
	}
	inventorySlots[30]->offsetX = 32;
	inventorySlots[30]->offsetY = 128;
	for (int i = 0; i < 6; i++)
	{
		inventorySlots[i + 31]->offsetX = 96 + (i / 3) * 64;
		inventorySlots[i + 31]->offsetY = 64 + (i % 3) * 64;
	}
}
