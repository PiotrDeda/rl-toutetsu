#pragma once

#include "../../engine/app/app.h"
#include "item_data.h"

class TestItem : public ItemData
{
public:
	TestItem()
	{
		this->sprite = App::get().getSprite("spell_zap");
		this->type = Spell;
	};

	[[nodiscard]] SpellStats getSpellStats() const override { return {5, 5, 1}; }
};
