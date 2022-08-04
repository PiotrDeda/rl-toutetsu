#include "entity.h"

Entity::Entity(const SurfacePtr& layer, const std::shared_ptr<::Sprite>& sprite)
{
	this->layer = layer;
	this->sprite = sprite;
}

void Entity::draw() const
{
	sprite->draw(x, y, layer);
}

void Entity::move(const int targetX, const int targetY)
{
	x = targetX;
	y = targetY;
}
