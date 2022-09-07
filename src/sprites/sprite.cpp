#include "sprite.h"
#include "../common/app.h"
#include "../common/logger.h"

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

void Sprite::draw(const int x, const int y)
{
	SDL_Rect dstRect = {x, y, width, height};
	SDL_RenderCopy(renderer, texture.get(), nullptr, &dstRect);
}

void Sprite::setState(int state) {}
