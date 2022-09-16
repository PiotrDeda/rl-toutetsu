#pragma once

#include <memory>
#include "sprites/sprite.h"
#include "camera/camera.h"
#include "sprites/i_renderable.h"

class GameObject : public IRenderable
{
public:
	explicit GameObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);

	void draw() const override;
	void move(int targetX, int targetY);

	int x = 0;
	int y = 0;
	std::shared_ptr<Sprite> sprite;
	std::shared_ptr<Camera> camera;
};
