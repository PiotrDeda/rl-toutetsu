#pragma once

#include "../../engine/game_object/i_renderable.h"
#include "tile.h"
#include "map_objects/player_puppet.h"

class Map : public IRenderable
{
public:
	static constexpr int tileSize = 64;

	Map(const std::shared_ptr<Camera>& camera, int mapSize);

	void draw() const override;
	[[nodiscard]] int getSize() const;
	void addFloor(const std::shared_ptr<MapObject>& object, int x, int y);
	void addWall(const std::shared_ptr<MapObject>& object, int x, int y);
	void addInteract(const std::shared_ptr<MapObject>& object, int x, int y);
	Tile& getFloor(int x, int y);
	Tile& getWall(int x, int y);
	Tile& getInteract(int x, int y);
	void moveInteract(int x, int y, int newX, int newY);
	void movePlayer(int directionX, int directionY);

	std::shared_ptr<PlayerPuppet> player;

private:
	std::shared_ptr<Camera> camera;
	std::vector<std::vector<Tile>> floorLayer;
	std::vector<std::vector<Tile>> wallLayer;
	std::vector<std::vector<Tile>> interactLayer;
	int mapSize;
};
