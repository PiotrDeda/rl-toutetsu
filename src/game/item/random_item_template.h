#pragma once

#include <memory>
#include "item_data.h"

class RandomItemTemplate
{
public:
	virtual std::shared_ptr<ItemData> generate() = 0;
};
