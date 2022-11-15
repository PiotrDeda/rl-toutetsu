#pragma once

#include "../scene_game_map/map_objects/floor.h"
#include "../scene_game_map/map_objects/wall.h"
#include "../scene_game_map/map_objects/wall_torch.h"

class FullyRandomMap
{
public:
	static void generateMap(const std::shared_ptr<Map>& map);
};

void FullyRandomMap::generateMap(const std::shared_ptr<Map>& map)
{
	for (int x = 0; x < map->getSize(); x++)
	{
		for (int y = 0; y < map->getSize(); y++)
		{
			if (rand() % 100 < 33 || x == 0 || y == 0 || x == map->getSize() - 1 || y == map->getSize() - 1)
			{
				if (rand() % 100 < 80)
					map->addWall(std::make_shared<Wall>(), x, y);
				else
					map->addWall(std::make_shared<WallTorch>(), x, y);
			}
			map->addFloor(std::make_shared<Floor>(), x, y);
		}
	}
	for (int x = 0; x < map->getSize(); x++)
	{
		for (int y = 0; y < map->getSize(); y++)
		{
			if (map->getWall(x, y).object == nullptr)
			{
				auto player = std::make_shared<PlayerPuppet>();
				map->addInteract(player, x, y);
				map->player = player;
				return;
			}
		}
	}
}
