#pragma once

#include "test_item.h"
#include "test_item_2.h"

class RandomItem
{
public:
	static std::shared_ptr<ItemData> generate(std::mt19937& gen)
	{
		std::uniform_int_distribution<> itemDistr(0, 1);
		std::shared_ptr<ItemData> item;
		if (itemDistr(gen) == 0)
			item = std::make_shared<TestItem>();
		else
			item = std::make_shared<TestItem2>();
		item->generate();
		return item;
	}
};
