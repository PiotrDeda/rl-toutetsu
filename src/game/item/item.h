#pragma once

#include <memory>
#include "../../engine/game_object/i_renderable.h"
#include "../../engine/sprite/sprite.h"

class Item
{
public:
	std::shared_ptr<Sprite> sprite;
};
