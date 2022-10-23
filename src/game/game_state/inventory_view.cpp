#include "inventory_view.h"

#include <utility>

InventoryView::InventoryView(std::shared_ptr<Inventory> inventory, const std::shared_ptr<Camera>& camera)
		: GameObject(nullptr, camera), inventory(std::move(inventory)) {}

void InventoryView::draw() const
{
	std::size_t i = 0;
	for (const auto& slot : inventory->inventorySlots)
	{
		if (i++ == inventory->cursorIndex)
			continue;
		slot->item->sprite->draw(x + slot->offsetX, y + slot->offsetY, camera->getScale());
	}
	int mouseX = App::get().getMouseX();
	int mouseY = App::get().getMouseY();
	auto sprite = inventory->inventorySlots[inventory->cursorIndex]->item->sprite;
	int width = sprite->getScaledWidth(camera->getScale());
	int height = sprite->getScaledHeight(camera->getScale());
	sprite->draw(mouseX - width / 2, mouseY - height / 2, camera->getScale());
}

bool InventoryView::isMouseOver(int mouseX, int mouseY)
{
	for (const auto& slot : inventory->inventorySlots) // NOLINT(readability-use-anyofallof)
	{
		if (slot->index != inventory->cursorIndex &&
			mouseX >= camera->getScreenX(x + slot->offsetX) &&
			mouseX <= camera->getScreenX(x + slot->offsetX) + slot->item->sprite->getScaledWidth(camera->getScale()) &&
			mouseY >= camera->getScreenY(y + slot->offsetY) &&
			mouseY <= camera->getScreenY(y + slot->offsetY) + slot->item->sprite->getScaledHeight(camera->getScale()))
		{
			lastClickedIndex = slot->index;
			return true;
		}
	}
	return false;
}

void InventoryView::onClick()
{
	inventory->switchCursorItem(lastClickedIndex);
}
