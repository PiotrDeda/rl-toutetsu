#pragma once

#include "../../engine/app/app.h"
#include "item.h"

class TestItem : public Item
{
public:
	TestItem()
	{
		this->sprite = App::get().getSprite("test_item");
		this->type = Spell;
	};

	[[nodiscard]] SpellStats getSpellStats() const override { return {5, 5, 1}; }
};
