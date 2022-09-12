#pragma once

#include <vector>
#include "sprite.h"

class AnimatedStateSprite : public Sprite
{
public:
	AnimatedStateSprite(const char* name, int frameCount, int delay, int stateCount);

	void draw(int x, int y, double scale) override;
	void setState(int state) override;

private:
	int frameCount;
	int currentFrame = 0;
	int delay;
	int currentDelay;
	int stateCount;
	int currentState = 0;
	std::vector<SDL_Rect> clips;
};
