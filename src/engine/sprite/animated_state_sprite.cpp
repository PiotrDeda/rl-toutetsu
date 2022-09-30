#include "animated_state_sprite.h"

AnimatedStateSprite::AnimatedStateSprite(const char* name, const int frameCount, const int delay, const int stateCount) : Sprite(name)
{
	this->frameCount = frameCount;
	this->delay = delay;
	this->currentDelay = delay;
	this->stateCount = stateCount;
	this->width = width / frameCount;
	this->height = height / stateCount;
	for (int i = 0; i < stateCount; i++)
		for (int j = 0; j < frameCount; j++)
			clips.push_back({j * width, i * height, width, height});
}

void AnimatedStateSprite::draw(int x, int y, const double scale)
{
	SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
	int clipIndex = currentState * frameCount + currentFrame;
	SDL_RenderCopy(renderer, texture.get(), &clips[clipIndex], &dstRect);
	if (--currentDelay == 0)
	{
		currentFrame = (currentFrame + 1) % frameCount;
		currentDelay = delay;
	}
}

void AnimatedStateSprite::setState(int state)
{
	currentState = (state < 0 || state >= stateCount) ? 0 : state;
}
