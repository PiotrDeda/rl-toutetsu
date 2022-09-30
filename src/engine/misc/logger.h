#pragma once

#include <string>
#include <SDL_error.h>
#include <SDL_log.h>
#include <SDL_image.h>

class Logger
{
public:
	template<typename... Args>
	static void logInfo(const char* message, Args... args)
	{
		SDL_Log(message, args...);
	}

	static void logInfo(const char* message)
	{
		SDL_Log("%s", message);
	}

	template<typename... Args>
	static void logWarning(const char* message, Args... args)
	{
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, message, args...);
	}

	static void logWarning(const char* message)
	{
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
	}

	template<typename... Args>
	static void logError(const char* message, Args... args)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message, args...);
	}

	static void logError(const char* message)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
	}

	template<typename... Args>
	static void logErrorSdl(const char* message, Args... args)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, message, args...);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[SDL_Error] %s", SDL_GetError());
	}

	static void logErrorSdl(const char* message)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", message);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[SDL_Error] %s", SDL_GetError());
	}

	template<typename... Args>
	static void logErrorImg(const char* message, Args... args)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message, args...);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[IMG_Error] %s", IMG_GetError());
	}

	static void logErrorImg(const char* message)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[IMG_Error] %s", IMG_GetError());
	}
};