#pragma once

#include <memory>
#include "../sprites/sprite.h"

class GameObject
{
public:
	explicit GameObject(const std::shared_ptr<Sprite>& sprite);

	void draw() const;
	void move(int targetX, int targetY);

	int x = 0;
	int y = 0;
	std::shared_ptr<Sprite> sprite;
};
