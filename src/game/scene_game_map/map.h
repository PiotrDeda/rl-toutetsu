#pragma once

#include "tile.h"
#include "../../engine/game_object/i_renderable.h"

class Map : public IRenderable
{
public:
	static constexpr int tileSize = 64;

	explicit Map(int mapSize);
	std::vector<Tile>& operator[](int x);

	void draw() const override;
	void addObject(const std::shared_ptr<MapObject>& object, int x, int y);

private:
	std::vector<std::vector<Tile>> tiles;
};
