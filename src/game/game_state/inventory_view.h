#pragma once

#include "../../engine/game_object/game_object.h"
#include "inventory.h"

class InventoryView : public GameObject
{
public:
	InventoryView(std::shared_ptr<Inventory> inventory, const std::shared_ptr<Camera>& camera);
	void draw() const override;

	std::shared_ptr<Inventory> inventory;
};
