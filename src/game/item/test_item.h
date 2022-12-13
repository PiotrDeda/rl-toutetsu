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
};
