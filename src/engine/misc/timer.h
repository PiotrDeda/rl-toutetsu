#pragma once

#include "logger.h"

class Timer
{
public:
	static SDL_TimerID startTimer(Uint32 interval, SDL_TimerCallback callback, void* param)
	{
		int result = SDL_AddTimer(interval, callback, param);
		if (result == 0)
			THROW_ERROR_SDL("Couldn't initialize timer");
		return result;
	}
};
