#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "../../engine/game_object/i_renderable.h"
#include "map_object.h"

class Tile : public IRenderable
{
public:
	void setPosition(int x, int y);
	void addObject(const std::shared_ptr<MapObject>& object);
	void draw() const override;
	std::vector<std::shared_ptr<MapObject>> objects;

private:
	int x;
	int y;
};
