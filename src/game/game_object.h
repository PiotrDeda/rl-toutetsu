#pragma once

#include <memory>
#include "../sprites/sprite.h"
#include "camera.h"

class GameObject
{
public:
	explicit GameObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);

	void draw() const;
	void move(int targetX, int targetY);

	int x = 0;
	int y = 0;
	std::shared_ptr<Sprite> sprite;
	std::shared_ptr<Camera> camera;
};
