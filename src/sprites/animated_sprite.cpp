#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite(const char* name, const int frameCount, const int delay) : Sprite(name)
{
	this->frameCount = frameCount;
	this->delay = delay;
	this->currentDelay = delay;
	this->width = width / frameCount;
	for (int i = 0; i < frameCount; i++)
		clips.push_back({i * width, 0, width, height});
}

void AnimatedSprite::draw(int x, int y)
{
	SDL_Rect dstRect = {x, y, width, height};
	SDL_RenderCopy(renderer, texture.get(), &clips[currentFrame], &dstRect);
	if (--currentDelay == 0)
	{
		currentFrame = (currentFrame + 1) % frameCount;
		currentDelay = delay;
	}
}
