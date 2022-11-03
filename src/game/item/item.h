#pragma once

#include <memory>
#include "../../engine/game_object/i_renderable.h"
#include "../../engine/sprite/sprite.h"

enum ItemType
{
	Blank,
	General,
	Weapon,
	Helmet,
	Armor,
	Boots,
	Trinket,
	Shield,
	Book
};

class Item
{
public:
	std::shared_ptr<Sprite> sprite;
	ItemType type = General;
};
