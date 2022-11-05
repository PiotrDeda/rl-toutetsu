#include "map.h"

Map::Map(int mapSize)
{
	tiles.resize(mapSize);
	for (int i = 0; i < mapSize; i++)
	{
		tiles[i].resize(mapSize);
		for (int j = 0; j < mapSize; j++)
			tiles[i][j].setPosition(i * tileSize, j * tileSize);
	}
}

std::vector<Tile>& Map::operator[](int x)
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
