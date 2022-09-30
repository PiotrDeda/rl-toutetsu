#pragma once

#include <vector>
#include "sprite.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(const char* name, int frameCount, int delay);

	void draw(int x, int y, double scale) override;

private:
	int frameCount;
	int currentFrame = 0;
	int delay;
	int currentDelay;
	std::vector<SDL_Rect> clips;
};
