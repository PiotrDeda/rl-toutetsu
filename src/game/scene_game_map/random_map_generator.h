#pragma once

#include <random>
#include <queue>
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

struct RoomConnection
{
	int room1;
	int room2;
	int distance;
};

class RandomMapGenerator
{
public:
	static void generateMap(const std::shared_ptr<Map>& map, RandomMapParameters parameters, unsigned int seed);

private:
	static void placeRoom(std::vector<std::vector<int>>& mapValues, int centerX, int centerY,
						  int sizeXLeft, int sizeXRight, int sizeYTop, int sizeYBottom);
	static void placeCorridor(std::vector<std::vector<int>>& valueMap,
							  int x1, int y1, int x2, int y2, std::mt19937& gen);
	static void
	convertValueMapToObjectMap(const std::vector<std::vector<int>>& valueMap, const std::shared_ptr<Map>& objectMap,
							   const RandomMapParameters& parameters, std::mt19937& gen);
};

void RandomMapGenerator::generateMap(const std::shared_ptr<Map>& objectMap, RandomMapParameters p, unsigned int seed)
{
	// seed random number generator
	std::mt19937 gen(seed);
	Logger::logInfo("Generating random map with seed %u", seed);

	// create int objectMap to store tiles
	std::vector<std::vector<int>> valueMap;
	for (int x = 0; x < objectMap->getSize(); x++)
	{
		valueMap.emplace_back();
		for (int y = 0; y < objectMap->getSize(); y++)
			valueMap[x].emplace_back(TileNothing);
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
		std::uniform_int_distribution<> roomXDistr(roomGridLocations[i].first * objectMap->getSize() / gridSize + 1,
												   (roomGridLocations[i].first + 1) * objectMap->getSize() / gridSize -
												   2);
		std::uniform_int_distribution<> roomYDistr(roomGridLocations[i].second * objectMap->getSize() / gridSize + 1,
												   (roomGridLocations[i].second + 1) * objectMap->getSize() / gridSize -
												   2);
		roomCenters.emplace_back(std::make_pair(roomXDistr(gen), roomYDistr(gen)));
		int sizeX = sizeDistr(gen), sizeY = sizeDistr(gen);
		placeRoom(valueMap, roomCenters[i].first, roomCenters[i].second, sizeX, sizeX, sizeY, sizeY);
		Logger::logInfo("Placed room [%d] with grid position [%d, %d] at [%d, %d] with size [%d, %d]",
						i, roomGridLocations[i].first, roomGridLocations[i].second,
						roomCenters[i].first, roomCenters[i].second, sizeX, sizeY);
	}

	// generate corridors
	std::vector<RoomConnection> roomConnections;
	for (int i = 0; i < roomAmount; i++)
		for (int j = i + 1; j < roomAmount; j++)
			roomConnections.emplace_back(RoomConnection{i, j, abs(roomCenters[i].first - roomCenters[j].first) +
															  abs(roomCenters[i].second - roomCenters[j].second)});
	std::sort(roomConnections.begin(), roomConnections.end(),
			  [](const RoomConnection& a, const RoomConnection& b) { return a.distance < b.distance; });
	for (int i = 0; i < roomAmount - 1; i++)
	{
		int room1 = roomConnections[i].room1, room2 = roomConnections[i].room2;
		int x1 = roomCenters[room1].first, y1 = roomCenters[room1].second;
		int x2 = roomCenters[room2].first, y2 = roomCenters[room2].second;
		placeCorridor(valueMap, x1, y1, x2, y2, gen);
		Logger::logInfo("Placed corridor between rooms [%d] and [%d]", room1, room2);
	}

	// detect room clusters
	std::vector<int> roomCluster(roomAmount, -1);
	int clusterCount = 0;
	for (int i = 0; i < roomAmount; i++)
	{
		if (roomCluster[i] != -1)
			continue;
		roomCluster[i] = clusterCount;
		std::queue<int> roomQueue;
		roomQueue.push(i);
		while (!roomQueue.empty())
		{
			int room = roomQueue.front();
			roomQueue.pop();
			for (int j = 0; j < roomAmount - 1; j++)
			{
				if (roomConnections[j].room1 == room && roomCluster[roomConnections[j].room2] == -1)
				{
					roomCluster[roomConnections[j].room2] = clusterCount;
					roomQueue.push(roomConnections[j].room2);
				}
				else if (roomConnections[j].room2 == room && roomCluster[roomConnections[j].room1] == -1)
				{
					roomCluster[roomConnections[j].room1] = clusterCount;
					roomQueue.push(roomConnections[j].room1);
				}
			}
		}
		clusterCount++;
	}
	clusterCount--;

	// place corridors between closest rooms in separate room clusters
	for (int i = 1; i <= clusterCount; i++)
	{
		int room1 = -1, room2 = -1;
		int minDistance = INT_MAX;
		for (int j = 0; j < roomAmount; j++)
		{
			for (int k = j + 1; k < roomAmount; k++)
			{
				int distance = abs(roomCenters[j].first - roomCenters[k].first) +
							   abs(roomCenters[j].second - roomCenters[k].second);
				if (distance < minDistance &&
					(roomCluster[j] == i && roomCluster[k] == i - 1 || roomCluster[j] == i - 1 && roomCluster[k] == i))
				{
					room1 = j;
					room2 = k;
					minDistance = distance;
				}
			}
		}
		int x1 = roomCenters[room1].first, y1 = roomCenters[room1].second;
		int x2 = roomCenters[room2].first, y2 = roomCenters[room2].second;
		placeCorridor(valueMap, x1, y1, x2, y2, gen);
		Logger::logInfo("Placed corridor between clustered rooms [%d] and [%d]", room1, room2);
	}

	// place entrance and exit
	int startRoom = roomConnections.back().room1, endRoom = roomConnections.back().room2;
	valueMap[roomCenters[startRoom].first][roomCenters[startRoom].second] = TileEntrance;
	valueMap[roomCenters[endRoom].first][roomCenters[endRoom].second] = TileExit;
	Logger::logInfo("Placed entrance in room [%d] and exit in room [%d]", startRoom, endRoom);

	// convert to real map
	convertValueMapToObjectMap(valueMap, objectMap, p, gen);
}

void RandomMapGenerator::placeRoom(std::vector<std::vector<int>>& mapValues, int centerX, int centerY,
								   int sizeXLeft, int sizeXRight, int sizeYTop, int sizeYBottom)
{
	// trim size to map edges
	if (centerX - sizeXLeft < 0)
		sizeXLeft = centerX;
	if (centerX + sizeXRight >= mapValues.size())
		sizeXRight = static_cast<int>(mapValues.size()) - centerX - 1;
	if (centerY - sizeYTop < 0)
		sizeYTop = centerY;
	if (centerY + sizeYBottom >= mapValues.size())
		sizeYBottom = static_cast<int>(mapValues.size()) - centerY - 1;

	// place floor
	for (int x = centerX - sizeXLeft + 1; x <= centerX + sizeXRight - 1; x++)
		for (int y = centerY - sizeYTop + 1; y <= centerY + sizeYBottom - 1; y++)
			mapValues[x][y] = TileFloor;

	// place top and bottom walls
	for (int x = centerX - sizeXLeft; x <= centerX + sizeXRight; x++)
	{
		if (mapValues[x][centerY - sizeYTop] == TileNothing)
			mapValues[x][centerY - sizeYTop] = TileWall;
		if (mapValues[x][centerY + sizeYBottom] == TileNothing)
			mapValues[x][centerY + sizeYBottom] = TileWall;
	}

	// place left and right walls
	for (int y = centerY - sizeYTop; y <= centerY + sizeYBottom; y++)
	{
		if (mapValues[centerX - sizeXLeft][y] == TileNothing)
			mapValues[centerX - sizeXLeft][y] = TileWall;
		if (mapValues[centerX + sizeXRight][y] == TileNothing)
			mapValues[centerX + sizeXRight][y] = TileWall;
	}
}

void RandomMapGenerator::placeCorridor(std::vector<std::vector<int>>& valueMap, int x1, int y1, int x2, int y2,
									   std::mt19937& gen)
{
	std::uniform_int_distribution<> boolDistr(0, 1);

	auto placeCorridorTile = [&](int x, int y) {
		valueMap[x][y] = TileFloor;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (valueMap[x + i][y + j] == TileNothing)
					valueMap[x + i][y + j] = TileWall;
	};

	if (boolDistr(gen))
	{
		for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++)
			placeCorridorTile(x, y1);
		for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++)
			placeCorridorTile(x2, y);
	}
	else
	{
		for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++)
			placeCorridorTile(x1, y);
		for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++)
			placeCorridorTile(x, y2);
	}
}

void RandomMapGenerator::convertValueMapToObjectMap(const std::vector<std::vector<int>>& valueMap,
													const std::shared_ptr<Map>& objectMap,
													const RandomMapParameters& p, std::mt19937& gen)
{
	objectMap->clear();
	std::uniform_int_distribution<> percentDistr(0, 99);
	for (int x = 0; x < objectMap->getSize(); x++)
	{
		for (int y = 0; y < objectMap->getSize(); y++)
		{
			switch (valueMap[x][y])
			{
				case TileWall:
					if (percentDistr(gen) < p.torchChance)
						objectMap->addWall(std::make_shared<WallTorch>(), x, y);
					else
						objectMap->addWall(std::make_shared<Wall>(), x, y);
					break;
				case TileFloor:
					objectMap->addFloor(std::make_shared<Floor>(), x, y);
					break;
				case TileEntrance:
				{
					objectMap->addFloor(std::make_shared<Floor>(), x, y);
					auto player = std::make_shared<PlayerPuppet>();
					objectMap->addInteract(player, x, y);
					objectMap->player = player;
					break;
				}
				case TileExit:
					objectMap->addFloor(std::make_shared<Floor>(), x, y);
					objectMap->addInteract(std::make_shared<WallTorch>(), x, y);
					break;
			}
		}
	}
}
