#pragma once

#include <vector>
#include "sprite.h"

class TextSprite : public Sprite
{
public:
	explicit TextSprite(const char* text);

	void setText(const char* text) override;
	void setTextColor(SDL_Color color) override;

protected:
	SDL_Color textColor = {255, 255, 255};
};
