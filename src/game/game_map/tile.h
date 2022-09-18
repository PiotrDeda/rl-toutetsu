#pragma once

#include <vector>
#include "../game_object.h"
#include "map_object.h"
#include "../i_renderable.h"

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
