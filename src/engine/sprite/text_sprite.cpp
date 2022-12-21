#include "text_sprite.h"

#include "../app/app.h"
#include "../misc/logger.h"

TextSprite::TextSprite(const char* text)
{
	this->renderer = App::get().renderer;

	SurfacePtr surface = makeSurface(TTF_RenderText_Blended_Wrapped(App::get().font.get(), text, textColor, 2000));
	if (!surface)
		THROW_ERROR_TTF("Failed to create surface from text: {}", text);
	this->texture = makeTexture(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
	if (!texture)
		THROW_ERROR_SDL("Failed to create texture from text surface: {}", text);
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void TextSprite::setText(const char* text)
{
	SurfacePtr surface = makeSurface(TTF_RenderText_Blended_Wrapped(App::get().font.get(), text, textColor, 2000));
	if (!surface)
		THROW_ERROR_TTF("Failed to create surface from text: {}", text);
	this->texture = makeTexture(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
	if (!texture)
		THROW_ERROR_SDL("Failed to create texture from text surface: {}", text);
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
}

void TextSprite::setTextColor(SDL_Color color)
{
	textColor = color;
}
