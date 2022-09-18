#pragma once

#include "../../common/sdl_pointers.h"

class Sprite
{
public:
	explicit Sprite(const char* name);

	virtual void draw(int x, int y, double scale);
	virtual void setState(int state);
	[[nodiscard]] int getScaledWidth(double scale) const;
	[[nodiscard]] int getScaledHeight(double scale) const;

	SDL_Renderer* renderer;
	TexturePtr texture;

protected:
	int width;
	int height;
};
