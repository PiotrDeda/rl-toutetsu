#pragma once

#include "../../engine/app/app.h"
#include "item_data.h"

class SpellWeapon : public ItemData
{
public:
	SpellWeapon()
	{
		this->sprite = App::get().getSprite("spell_weapon");
		this->type = Spell;
	};

	[[nodiscard]] SpellStats getSpellStats() const override { return {5, 5, 1}; }
};
