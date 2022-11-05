#include "sprite.h"

#include <SDL_image.h>
#include <SDL_surface.h>
#include "../app/app.h"
#include "../misc/logger.h"


Sprite::Sprite(const char* name) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
	this->renderer = App::get().renderer;
	this->texture = makeTexture(IMG_LoadTexture(renderer.get(), App::getAssetPath(name)));
	if (!texture)
	{
		Logger::logErrorIMG("Failed to load texture: %s", name);
		throw std::runtime_error("Failed to load texture " + std::string(name));
	}
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void Sprite::draw(const int x, const int y, const double scale)
{
	SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
	SDL_RenderCopy(renderer.get(), texture.get(), nullptr, &dstRect);
}

void Sprite::setState(int state) {}

void Sprite::setText(const char* text) {}

int Sprite::getScaledWidth(double scale) const
{
	return static_cast<int>(width * scale);
}

int Sprite::getScaledHeight(double scale) const
{
	return static_cast<int>(height * scale);
}
