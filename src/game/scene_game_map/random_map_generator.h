#pragma once

#include <random>
#include "../../engine/misc/logger.h"
#include "map_objects/floor.h"
#include "map_objects/wall.h"
#include "map_objects/wall_torch.h"

enum MapValues
{
	TileNothing = 0,
	TileWall = 1,
	TileFloor = 2,
	TileEntrance = 3,
	TileExit = 4
};

struct RandomMapParameters
{
	int minRoomAmount = 8;
	int maxRoomAmount = 10;
	int minRoomSize = 2;
	int maxRoomSize = 4;
	int torchChance = 10;
};

class RandomMapGenerator
{
public:
	static void generateMap(const std::shared_ptr<Map>& map, RandomMapParameters parameters, int seed);

private:
	static void placeRoom(std::vector<std::vector<int>>& mapValues, int centerX, int centerY, int sizeX, int sizeY);
};

void RandomMapGenerator::generateMap(const std::shared_ptr<Map>& map, RandomMapParameters p, int seed)
{
	// seed random number generator
	std::mt19937 gen(seed);

	// create int map to store tiles
	std::vector<std::vector<int>> mapValues;
	for (int x = 0; x < map->getSize(); x++)
	{
		mapValues.emplace_back();
		for (int y = 0; y < map->getSize(); y++)
			mapValues[x].emplace_back(TileNothing);
	}

	// generate room amount
	std::uniform_int_distribution<> roomDistr(p.minRoomAmount, p.maxRoomAmount);
	int roomAmount = roomDistr(gen);

	// generate room grid locations
	int gridSize = floor(sqrt(roomAmount * 2));
	std::vector<std::pair<int, int>> roomGridLocations(gridSize * gridSize);
	for (int x = 0; x < gridSize; x++)
		for (int y = 0; y < gridSize; y++)
			roomGridLocations[x * gridSize + y] = std::make_pair(x, y);
	std::shuffle(roomGridLocations.begin(), roomGridLocations.end(), gen);

	// generate rooms
	std::vector<std::pair<int, int>> roomCenters;
	std::uniform_int_distribution<> sizeDistr(p.minRoomSize, p.maxRoomSize);
	for (int i = 0; i < roomAmount; i++)
	{
		std::uniform_int_distribution<> roomXDistr(roomGridLocations[i].first * map->getSize() / gridSize,
												   (roomGridLocations[i].first + 1) * map->getSize() / gridSize - 1);
		std::uniform_int_distribution<> roomYDistr(roomGridLocations[i].second * map->getSize() / gridSize,
												   (roomGridLocations[i].second + 1) * map->getSize() / gridSize - 1);
		roomCenters.emplace_back(std::make_pair(roomXDistr(gen), roomYDistr(gen)));
		int sizeX = sizeDistr(gen), sizeY = sizeDistr(gen);
		placeRoom(mapValues, roomCenters[i].first, roomCenters[i].second, sizeX, sizeY);
		Logger::logInfo("Placing room with grid position [%d, %d] at [%d, %d] with size [%d, %d]",
						roomGridLocations[i].first, roomGridLocations[i].second,
						roomCenters[i].first, roomCenters[i].second, sizeX, sizeY);
	}

	// place entrance and exit
	int maxDistance = 0;
	int startRoom, endRoom;
	for (int i = 0; i < roomCenters.size(); i++)
	{
		for (int j = i + 1; j < roomCenters.size(); j++)
		{
			int distance = std::abs(roomCenters[i].first - roomCenters[j].first) +
						   std::abs(roomCenters[i].second - roomCenters[j].second);
			if (distance > maxDistance)
			{
				maxDistance = distance;
				startRoom = i;
				endRoom = j;
			}
		}
	}
	mapValues[roomCenters[startRoom].first][roomCenters[startRoom].second] = TileEntrance;
	mapValues[roomCenters[endRoom].first][roomCenters[endRoom].second] = TileExit;

	// convert map values to map objects
	std::uniform_int_distribution<> torchDistr(0, 99);
	for (int x = 0; x < map->getSize(); x++)
	{
		for (int y = 0; y < map->getSize(); y++)
		{
			switch (mapValues[x][y])
			{
				case TileWall:
					if (torchDistr(gen) < p.torchChance)
						map->addWall(std::make_shared<WallTorch>(), x, y);
					else
						map->addWall(std::make_shared<Wall>(), x, y);
					break;
				case TileFloor:
					map->addFloor(std::make_shared<Floor>(), x, y);
					break;
				case TileEntrance:
				{
					map->addFloor(std::make_shared<Floor>(), x, y);
					auto player = std::make_shared<PlayerPuppet>();
					map->addInteract(player, x, y);
					map->player = player;
					break;
				}
				case TileExit:
					map->addFloor(std::make_shared<Floor>(), x, y);
					map->addInteract(std::make_shared<WallTorch>(), x, y);
					break;
			}
		}
	}
}

void RandomMapGenerator::placeRoom(std::vector<std::vector<int>>& mapValues,
								   int centerX, int centerY, int sizeX, int sizeY)
{
	int sizeXLeft = sizeX, sizeXRight = sizeX;
	int sizeYTop = sizeY, sizeYBottom = sizeY;
	if (centerX - sizeXLeft < 0)
		sizeXLeft = centerX;
	if (centerX + sizeXRight >= mapValues.size())
		sizeXRight = static_cast<int>(mapValues.size()) - centerX - 1;
	if (centerY - sizeYTop < 0)
		sizeYTop = centerY;
	if (centerY + sizeYBottom >= mapValues.size())
		sizeYBottom = static_cast<int>(mapValues.size()) - centerY - 1;

	for (int x = centerX - sizeXLeft + 1; x <= centerX + sizeXRight - 1; x++)
		for (int y = centerY - sizeYTop + 1; y <= centerY + sizeYBottom - 1; y++)
			mapValues[x][y] = TileFloor;

	for (int x = centerX - sizeXLeft; x <= centerX + sizeXRight; x++)
	{
		if (mapValues[x][centerY - sizeYTop] == TileNothing)
			mapValues[x][centerY - sizeYTop] = TileWall;
		if (mapValues[x][centerY + sizeYBottom] == TileNothing)
			mapValues[x][centerY + sizeYBottom] = TileWall;
	}

	for (int y = centerY - sizeYTop; y <= centerY + sizeYBottom; y++)
	{
		if (mapValues[centerX - sizeXLeft][y] == TileNothing)
			mapValues[centerX - sizeXLeft][y] = TileWall;
		if (mapValues[centerX + sizeXRight][y] == TileNothing)
			mapValues[centerX + sizeXRight][y] = TileWall;
	}
}
