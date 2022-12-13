#pragma once

#include <memory>
#include "../../engine/sprite/sprite.h"

class Enemy
{
public:
	std::shared_ptr<Sprite> sprite;
};
