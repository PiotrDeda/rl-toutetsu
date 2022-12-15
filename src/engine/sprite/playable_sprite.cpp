#include "playable_sprite.h"

PlayableSprite::PlayableSprite(const char* name, const int frameCount, const int delay) : Sprite(name)
{
	this->frameCount = frameCount;
	this->delay = delay;
	this->width = width / frameCount;
	for (int i = 0; i < frameCount; i++)
		clips.push_back({i * width, 0, width, height});
}

void PlayableSprite::draw(int x, int y, const double scale)
{
	if (playing)
	{
		if (SDL_GetTicks64() - startingTime > delay * frameCount - 1)
		{
			playing = false;
			playCallback(callbackParam);
			return;
		}
		SDL_Rect dstRect = {x, y, getScaledWidth(scale), getScaledHeight(scale)};
		SDL_RenderCopy(renderer.get(), texture.get(),
					   &clips[(SDL_GetTicks64() - startingTime) / delay % frameCount], &dstRect);
	}
}

void PlayableSprite::play(PlayCallback callback, void* param)
{
	playing = true;
	startingTime = SDL_GetTicks64();
	playCallback = callback;
	callbackParam = param;
}
