#pragma once

#include "../util/sdl_pointers.h"

class Sprite
{
public:
	explicit Sprite(const char* path);

	void draw(int x, int y) const;

	SDL_Renderer* renderer;
	TexturePtr texture;

private:
	int width;
	int height;
};
