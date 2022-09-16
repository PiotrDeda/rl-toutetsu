#include "map.h"

Map::Map()
{
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)
			tiles[i][j].setPosition(i * tileSize, j * tileSize);
}

std::array<Tile, Map::mapSize>& Map::operator[](int x)
{
	return tiles[x];
}

void Map::addObject(const std::shared_ptr<MapObject>& object, int x, int y)
{
	tiles[x][y].addObject(object);
}

void Map::draw() const
{
	for (auto& row : tiles)
		for (auto& tile : row)
			tile.draw();
}
