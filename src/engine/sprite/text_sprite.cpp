#include "text_sprite.h"

#include "../app/app.h"
#include "../misc/logger.h"

TextSprite::TextSprite(const char* text)
{
	this->renderer = App::get().renderer;

	SurfacePtr surface = makeSurface(TTF_RenderText_Blended_Wrapped(App::get().font.get(), text, textColor, 2000));
	if (!surface)
	{
		Logger::logErrorTTF("Failed to create surface from text: %s", text);
		throw std::runtime_error("Failed to create surface from text: " + std::string(text));
	}
	this->texture = makeTexture(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
	if (!texture)
	{
		Logger::logErrorSDL("Failed to create texture from text surface: %s", text);
		throw std::runtime_error("Failed to create texture from text surface: " + std::string(text));
	}
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void TextSprite::setText(const char* text)
{
	SurfacePtr surface = makeSurface(TTF_RenderText_Blended_Wrapped(App::get().font.get(), text, textColor, 2000));
	if (!surface)
	{
		Logger::logErrorTTF("Failed to create surface from text: %s", text);
		throw std::runtime_error("Failed to create surface from text: " + std::string(text));
	}
	this->texture = makeTexture(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
	if (!texture)
	{
		Logger::logErrorSDL("Failed to create texture from text surface: %s", text);
		throw std::runtime_error("Failed to create texture from text surface: " + std::string(text));
	}
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}
