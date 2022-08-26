#pragma once

#include <vector>
#include "../engine/game_object.h"

class Tile
{
public:
	void setPosition(int x, int y);
	void addObject(const std::shared_ptr<GameObject>& object);
	void draw() const;
	std::vector<std::shared_ptr<GameObject>> objects;

private:
	int x;
	int y;
};
