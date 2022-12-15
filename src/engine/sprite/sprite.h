#pragma once

#include "../misc/sdl_pointers.h"

typedef void (* PlayCallback)(void* param);

class Sprite
{
public:
	explicit Sprite(const char* name);

	virtual void draw(int x, int y, double scale);
	virtual void setState(int state);
	virtual void setText(const char* text);
	virtual void play(PlayCallback callback, void* param);
	[[nodiscard]] int getWidth() const;
	[[nodiscard]] int getHeight() const;
	[[nodiscard]] int getScaledWidth(double scale) const;
	[[nodiscard]] int getScaledHeight(double scale) const;

	RendererPtr renderer;
	TexturePtr texture;

protected:
	Sprite() = default;

	int width = 0;
	int height = 0;
};
