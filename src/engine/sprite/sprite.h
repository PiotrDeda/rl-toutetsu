#pragma once

#include "../misc/sdl_pointers.h"

class Sprite
{
public:
	explicit Sprite(const char* name);

	virtual void draw(int x, int y, double scale);
	virtual void setState(int state);
	[[nodiscard]] int getScaledWidth(double scale) const;
	[[nodiscard]] int getScaledHeight(double scale) const;

	RendererPtr renderer;
	TexturePtr texture;

protected:
	Sprite() = default;

	int width = 0;
	int height = 0;
};
