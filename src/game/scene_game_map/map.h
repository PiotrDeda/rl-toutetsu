#pragma once

#include "../../engine/game_object/i_renderable.h"
#include "tile.h"

class Map : public IRenderable
{
public:
	static constexpr int tileSize = 64;

	Map(const std::shared_ptr<Camera>& camera, int mapSize);
	std::vector<Tile>& operator[](int x);

	void draw() const override;
	void addObject(const std::shared_ptr<MapObject>& object, int x, int y);
	[[nodiscard]] int getSize() const;

private:
	std::shared_ptr<Camera> camera;
	std::vector<std::vector<Tile>> tiles;
	int mapSize;
};
