#include "state_sprite.h"

StateSprite::StateSprite(const char* name, const int stateCount) : Sprite(name)
{
	this->stateCount = stateCount;
	this->height = height / stateCount;
	for (int i = 0; i < stateCount; i++)
		clips.push_back({0, i * height, width, height});
}

void StateSprite::draw(int x, int y, const double scale)
{
	SDL_Rect dstRect = {static_cast<int>(x * scale), static_cast<int>(y * scale), static_cast<int>(width * scale), static_cast<int>(height * scale)};
	SDL_RenderCopy(renderer, texture.get(), &clips[currentState], &dstRect);
}

void StateSprite::setState(int state)
{
	currentState = (state < 0 || state >= stateCount) ? 0 : state;
}
