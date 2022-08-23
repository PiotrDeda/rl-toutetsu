#pragma once

#include "../util/sdl_pointers.h"

class Sprite
{
public:
	explicit Sprite(const char* name);

	virtual void draw(int x, int y);
	virtual void setState(int state);

	SDL_Renderer* renderer;
	TexturePtr texture;

protected:
	int width;
	int height;
};
