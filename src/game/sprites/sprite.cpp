#include "sprite.h"
#include "../../common/app.h"
#include "../../common/logger.h"

#include <SDL_surface.h>
#include <SDL_image.h>

Sprite::Sprite(const char* name) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
	this->renderer = App::get().renderer.get();
	this->texture = makeTexture(IMG_LoadTexture(renderer, App::getAssetPath(name)));
	if (!texture)
	{
		Logger::logErrorImg("Failed to load texture: %s", name);
		throw std::runtime_error("Failed to load texture " + std::string(name));
	}
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void Sprite::draw(const int x, const int y, const double scale)
{
	SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
	SDL_RenderCopy(renderer, texture.get(), nullptr, &dstRect);
}

void Sprite::setState(int state) {}

int Sprite::getScaledWidth(double scale) const
{
	return static_cast<int>(width * scale);
}

int Sprite::getScaledHeight(double scale) const
{
	return static_cast<int>(height * scale);
}
