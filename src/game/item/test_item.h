#pragma once

#include "item.h"
#include "../../engine/app/app.h"

class TestItem : public Item
{
public:
	TestItem() { this->sprite = App::get().getSprite("test_item"); };
};
