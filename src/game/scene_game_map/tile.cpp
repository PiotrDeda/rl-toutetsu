#include "tile.h"

void Tile::draw() const {}

void Tile::draw(const std::shared_ptr<Camera>& camera) const
{
	if (enabled && object)
		object->sprite->draw(camera->getScreenX(x), camera->getScreenY(y), camera->getScale());
}

void Tile::setObject(const std::shared_ptr<MapObject>& newObject)
{
	object = newObject;
	object->setPosition(x, y);
}

void Tile::removeObject()
{
	object = nullptr;
}

bool Tile::isMouseOver(int mouseX, int mouseY)
{
	return false;
}
