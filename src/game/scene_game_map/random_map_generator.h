#pragma once

#include <memory>
#include <random>
#include "map.h"

enum MapValues : char
{
	TileNothing = ' ',
	TileWallRandom = 'W',
	TileWall = 'w',
	TileWallTorch = 't',
	TileFloor = '.',
	TileEntrance = 'O',
	TileExit = 'X',
	TileItem = 'I',
	TileEnemy = 'E',
	ReservedFloor = -1
};

struct RandomMapParameters
{
	int minRoomAmount = 8;
	int maxRoomAmount = 10;
	int minRoomSize = 2;
	int maxRoomSize = 4;
	int torchChance = 10;
	int itemChance = 4;
	int enemyChance = 4;
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
	static void
	generateMap(const std::shared_ptr<Map>& map, RandomMapParameters parameters, unsigned int seed);

private:
	static void placeRoom(std::vector<std::vector<int>>& mapValues, int centerX, int centerY,
						  int sizeXLeft, int sizeXRight, int sizeYTop, int sizeYBottom);
	static void placeCorridor(std::vector<std::vector<int>>& valueMap,
							  int x1, int y1, int x2, int y2, std::mt19937& gen);
	static void convertValueMapToObjectMap(const std::vector<std::vector<int>>& valueMap,
										   const std::shared_ptr<Map>& objectMap,
										   const RandomMapParameters& parameters, std::mt19937& gen);
};
