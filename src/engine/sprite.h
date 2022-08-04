#pragma once

#include "../util/sdl_pointers.h"

class Sprite
{
public:
	explicit Sprite(const SurfacePtr& surface);

	void draw(int x, int y, const SurfacePtr& layer) const;

	SurfacePtr surface;
};
