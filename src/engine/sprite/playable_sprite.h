#pragma once

#include <vector>
#include "sprite.h"

class PlayableSprite : public Sprite
{
public:
	PlayableSprite(const char* name, int frameCount, int delay);

	void draw(int x, int y, double scale) override;
	void play(PlayCallback callback, void* param) override;

private:

	int frameCount;
	int delay;
	bool playing = false;
	Uint64 startingTime = 0;
	std::vector<SDL_Rect> clips;
	PlayCallback playCallback = nullptr;
	void* callbackParam = nullptr;
};
