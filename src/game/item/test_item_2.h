#pragma once

#include "item.h"
#include "../../engine/app/app.h"

class TestItem2 : public Item
{
public:
	TestItem2()
	{
		this->sprite = App::get().getSprite("test_item_2");
		this->type = Helmet;
	};
};
