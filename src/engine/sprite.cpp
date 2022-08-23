#include "sprite.h"
#include "../common/app.h"
#include "../util/logger.h"

#include <SDL_surface.h>
#include <SDL_image.h>

Sprite::Sprite(const char* path) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
	this->renderer = App::get().renderer.get();
	this->texture = makeTexture(IMG_LoadTexture(renderer, getPath(path)));
	if (!texture)
		Logger::logErrorImg("Failed to load texture: %s", path);
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void Sprite::draw(const int x, const int y) const
{
	SDL_Rect dstRect = {x, y, width, height};
	SDL_RenderCopy(renderer, texture.get(), nullptr, &dstRect);
}

const char* Sprite::getPath(const char* path)
{
	const char* prefix = "../src/assets/";
	const char* suffix = ".png";
	char* result = new char[strlen(prefix) + strlen(path) + strlen(suffix) + 1];
	strcpy(result, prefix);
	strcat(result, path);
	strcat(result, suffix);
	return result;
}
