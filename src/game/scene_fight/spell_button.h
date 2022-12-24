#pragma once

#include "../../engine/game_object/game_object.h"
#include "../item/item_data.h"

class SpellButton : public GameObject
{
public:
	explicit SpellButton(const std::shared_ptr<Camera>& camera);

	void draw() const override;
	[[nodiscard]] bool isMouseOver(int mouseX, int mouseY) override;
	void onClick() override;

	std::shared_ptr<ItemData> spell;
	bool clickable = true;
};
