#include "sprite.h"

#include <SDL_image.h>
#include <SDL_surface.h>
#include "../app/app.h"
#include "../misc/logger.h"

Sprite::Sprite(const char* name)
{
	this->renderer = App::get().renderer;
	this->texture = makeTexture(IMG_LoadTexture(renderer.get(), App::getAssetPath(name)));
	if (!texture)
		THROW_ERROR_IMG("Failed to load texture: {}", name);
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void Sprite::draw(const int x, const int y, const double scale)
{
	SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
	SDL_RenderCopy(renderer.get(), texture.get(), nullptr, &dstRect);
}

void Sprite::setState(int state) {}

void Sprite::setText(const char* text) {}

void Sprite::setTextColor(SDL_Color color) {}

void Sprite::play(PlayCallback callback, void* param)
{
	callback(param);
}

int Sprite::getWidth() const
{
	return width;
}

int Sprite::getHeight() const
{
	return height;
}

int Sprite::getScaledWidth(double scale) const
{
	return static_cast<int>(width * scale);
}

int Sprite::getScaledHeight(double scale) const
{
	return static_cast<int>(height * scale);
}
