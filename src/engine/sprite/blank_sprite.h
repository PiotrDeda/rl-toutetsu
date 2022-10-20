#pragma once

#include <SDL_image.h>
#include "sprite.h"
#include "../app/app.h"

class BlankSprite : public Sprite
{
public:
	BlankSprite()
	{
		// TODO: remove function
		this->renderer = App::get().renderer;
		this->texture = makeTexture(IMG_LoadTexture(renderer.get(), App::getAssetPath("test_item")));
		if (!texture)
			throw std::runtime_error("Failed to load texture test_item");
		SDL_QueryTexture(texture.get(), nullptr, nullptr, &this->width, &this->height);
	}

	void draw(int x, int y, double scale) override
	{
		// TODO: remove function content
		SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
		SDL_RenderCopy(renderer.get(), texture.get(), nullptr, &dstRect);
	}
};
