#include "tile.h"

void Tile::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Tile::draw() const
{
	for (auto& object : objects)
		object->draw();
}

void Tile::addObject(const std::shared_ptr<GameObject>& object)
{
	objects.push_back(object);
	object->move(x, y);
}
