#include "tile.h"

void Tile::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Tile::draw() const {}

void Tile::draw(const std::shared_ptr<Camera>& camera) const
{
	for (auto& object : objects)
		object->draw(camera);
}

void Tile::addObject(const std::shared_ptr<MapObject>& object)
{
	objects.push_back(object);
	object->move(x, y);
}
