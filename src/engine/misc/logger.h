#pragma once

#include <SDL_error.h>
#include <SDL_image.h>
#include <SDL_log.h>
#include <SDL_ttf.h>
#include <fmt/core.h>
#include <string>

#define LOG_INFO(...) \
Logger::logInfo(fmt::format(__VA_ARGS__))

#define LOG_WARNING(...) \
Logger::logWarning(fmt::format(__VA_ARGS__))

#define THROW_ERROR(...) \
Logger::throwError(fmt::format(__VA_ARGS__))

#define THROW_ERROR_SDL(...) \
Logger::throwErrorSDL(fmt::format(__VA_ARGS__))

#define THROW_ERROR_IMG(...) \
Logger::throwErrorIMG(fmt::format(__VA_ARGS__))

#define THROW_ERROR_TTF(...) \
Logger::throwErrorTTF(fmt::format(__VA_ARGS__))

class Logger
{
public:
	static void logInfo(const std::string& message)
	{
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "%s", message.c_str());
	}

	static void logWarning(const std::string& message)
	{
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", message.c_str());
	}

	static void throwError(const std::string& message)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message.c_str());
		showErrorBox(message);
		throw std::runtime_error(message);
	}

	static void throwErrorSDL(const std::string& message)
	{
		auto formattedMessage = fmt::format("{}\n[SDL_Error] {}", message, SDL_GetError());
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", formattedMessage.c_str());
		showErrorBox(formattedMessage);
		throw std::runtime_error(formattedMessage);
	}

	static void throwErrorIMG(const std::string& message)
	{
		auto formattedMessage = fmt::format("{}\n[IMG_Error] {}", message, IMG_GetError());
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", formattedMessage.c_str());
		showErrorBox(formattedMessage);
		throw std::runtime_error(formattedMessage);
	}

	static void throwErrorTTF(const std::string& message)
	{
		auto formattedMessage = fmt::format("{}\n[TTF_Error] {}", message, TTF_GetError());
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", formattedMessage.c_str());
		showErrorBox(formattedMessage);
		throw std::runtime_error(formattedMessage);
	}

private:
	static void showErrorBox(const std::string& message)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "An error has occurred", message.c_str(), nullptr);
	}
};
