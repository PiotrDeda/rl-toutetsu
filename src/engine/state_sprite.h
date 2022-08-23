#pragma once

#include <vector>
#include "sprite.h"

class StateSprite : public Sprite
{
public:
	StateSprite(const char* name, int stateCount);

	void draw(int x, int y) override;
	void setState(int state) override;

private:
	int stateCount;
	int currentState = 0;
	std::vector<SDL_Rect> clips;
};
