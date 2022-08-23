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
	static const char* getPath(const char* path);

	int width;
	int height;
};
