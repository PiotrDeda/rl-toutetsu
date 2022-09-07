#include "game_object.h"

GameObject::GameObject(const std::shared_ptr<Sprite>& sprite)
{
	this->sprite = sprite;
}

void GameObject::draw() const
{
	sprite->draw(getRealX(), getRealY());
}

void GameObject::move(const int targetX, const int targetY)
{
	x = targetX;
	y = targetY;
}

int GameObject::getRealX() const
{
	return x;
}

int GameObject::getRealY() const
{
	return y;
}
