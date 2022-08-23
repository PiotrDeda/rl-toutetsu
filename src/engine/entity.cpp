#include "entity.h"

Entity::Entity(const std::shared_ptr<Sprite>& sprite)
{
	this->sprite = sprite;
}

void Entity::draw() const
{
	sprite->draw(x, y);
}

void Entity::move(const int targetX, const int targetY)
{
	x = targetX;
	y = targetY;
}
