#pragma once

#include "../engine/game_object.h"
#include "tile.h"

class Map
{
public:
	static constexpr int mapSize = 40;
	static constexpr int tileSize = 64;

	Map();
	std::array<Tile, mapSize>& operator[](int x);

	void draw() const;
	void addObject(const std::shared_ptr<GameObject>& object, int x, int y);

private:
	std::array<std::array<Tile, mapSize>, mapSize> tiles;
};
