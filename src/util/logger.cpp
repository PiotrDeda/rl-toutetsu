#include "logger.h"
#include <SDL_error.h>
#include <SDL_log.h>

void Logger::logInfo(const char* message)
{
	SDL_Log("%s", message);
}

void Logger::logWarning(const char* message)
{
	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
}

void Logger::logError(const char* message)
{
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[SDL_Error] %s", SDL_GetError());
}
