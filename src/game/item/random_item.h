#pragma once

#include "test_item.h"
#include "test_item_2.h"

class RandomItem
{
public:
	static std::shared_ptr<Item> generate(std::mt19937& gen)
	{
		std::uniform_int_distribution<> itemDistr(0, 1);
		if (itemDistr(gen) == 0)
			return std::make_shared<TestItem>();
		else
			return std::make_shared<TestItem2>();
	}
};
