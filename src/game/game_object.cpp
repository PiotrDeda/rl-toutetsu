#include "game_object.h"

GameObject::GameObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera)
{
	this->sprite = sprite;
	this->camera = camera;
}

void GameObject::draw() const
{
	sprite->draw(camera->getScreenX(x), camera->getScreenY(y), camera->getScale());
}

void GameObject::move(const int targetX, const int targetY)
{
	x = targetX;
	y = targetY;
}
