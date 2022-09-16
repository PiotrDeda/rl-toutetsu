#pragma once

#include "../game_object.h"
#include "tile.h"
#include "../sprites/i_renderable.h"

class Map : public IRenderable
{
public:
	static constexpr int mapSize = 40;
	static constexpr int tileSize = 64;

	Map();
	std::array<Tile, mapSize>& operator[](int x);

	void draw() const override;
	void addObject(const std::shared_ptr<MapObject>& object, int x, int y);

private:
	std::array<std::array<Tile, mapSize>, mapSize> tiles;
};
