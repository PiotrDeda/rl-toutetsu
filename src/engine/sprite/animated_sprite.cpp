#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite(const char* name, const int frameCount, const int delay) : Sprite(name)
{
	this->frameCount = frameCount;
	this->delay = delay;
	this->width = width / frameCount;
	for (int i = 0; i < frameCount; i++)
		clips.push_back({i * width, 0, width, height});
}

void AnimatedSprite::draw(int x, int y, const double scale)
{
	SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
	SDL_RenderCopy(renderer.get(), texture.get(), &clips[SDL_GetTicks64() / delay % frameCount], &dstRect);
}
