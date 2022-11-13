#include "map.h"

Map::Map(const std::shared_ptr<Camera>& camera, int mapSize)
{
	this->mapSize = mapSize;
	this->camera = camera;
	floorLayer.resize(mapSize);
	wallLayer.resize(mapSize);
	interactLayer.resize(mapSize);
	for (int i = 0; i < mapSize; i++)
	{
		floorLayer[i].resize(mapSize);
		wallLayer[i].resize(mapSize);
		interactLayer[i].resize(mapSize);
		for (int j = 0; j < mapSize; j++)
		{
			floorLayer[i][j].move(i * tileSize, j * tileSize);
			wallLayer[i][j].move(i * tileSize, j * tileSize);
			interactLayer[i][j].move(i * tileSize, j * tileSize);
		}
	}
}

void Map::addFloor(const std::shared_ptr<MapObject>& object, int x, int y)
{
	floorLayer[x][y].setObject(object);
}

void Map::addWall(const std::shared_ptr<MapObject>& object, int x, int y)
{
	wallLayer[x][y].setObject(object);
}

void Map::addInteract(const std::shared_ptr<MapObject>& object, int x, int y)
{
	interactLayer[x][y].setObject(object);
}

Tile& Map::getFloor(int x, int y)
{
	return floorLayer[x][y];
}

Tile& Map::getWall(int x, int y)
{
	return wallLayer[x][y];
}

Tile& Map::getInteract(int x, int y)
{
	return interactLayer[x][y];
}

void Map::draw() const
{
	for (auto& row : floorLayer)
		for (auto& tile : row)
			tile.draw(camera);
	for (auto& row : wallLayer)
		for (auto& tile : row)
			tile.draw(camera);
	for (auto& row : interactLayer)
		for (auto& tile : row)
			tile.draw(camera);
}

int Map::getSize() const
{
	return mapSize;
}
