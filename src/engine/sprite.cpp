#include "sprite.h"

#include <SDL_surface.h>

Sprite::Sprite(const SurfacePtr& surface)
{
	this->surface = surface;
}

void Sprite::draw(const int x, const int y, const SurfacePtr& layer) const
{
	SDL_Rect offset = {x, y, 0, 0};
	SDL_BlitSurface(surface.get(), nullptr, layer.get(), &offset);
}
