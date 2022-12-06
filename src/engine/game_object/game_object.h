#pragma once

#include <memory>
#include "../sprite/sprite.h"
#include "../camera/camera.h"
#include "i_renderable.h"

class GameObject : public IRenderable
{
public:
	GameObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);

	void draw() const override;
	virtual void setPosition(int targetX, int targetY);
	[[nodiscard]] virtual bool isMouseOver(int mouseX, int mouseY);
	virtual void onClick();

	int x = 0;
	int y = 0;
	std::shared_ptr<Sprite> sprite;
	std::shared_ptr<Camera> camera;

protected:
	explicit GameObject(const std::shared_ptr<Camera>& camera);
};
