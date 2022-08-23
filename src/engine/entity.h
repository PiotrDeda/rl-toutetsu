#pragma once

#include <memory>
#include "sprite.h"

class Entity
{
public:
	explicit Entity(const std::shared_ptr<Sprite> &sprite);

	void draw() const;
	void move(int targetX, int targetY);

	int x = 0;
	int y = 0;
	SurfacePtr layer;
	std::shared_ptr<Sprite> sprite;
};
