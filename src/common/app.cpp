#include "app.h"

#include <stdexcept>

#include "../util/logger.h"

App::~App()
{
	Logger::logInfo("Quitting SDL...");
	SDL_Quit();
}

void App::init()
{
	Logger::logInfo("Starting SDL...");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Logger::logError("SDL could not initialize!");
		throw std::runtime_error("SDL could not initialize!");
	}

	window = makeWindow(SDL_CreateWindow("Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										 defaultWidth, defaultHeight, SDL_WINDOW_SHOWN));
	if (!window.get())
	{
		Logger::logError("Window could not be created!");
		throw std::runtime_error("Window could not be created!");
	}

	windowSurface = makeSurface(SDL_GetWindowSurface(window.get()));

	if (!windowSurface.get())
	{
		Logger::logError("Window surface could not be created!");
		throw std::runtime_error("Window surface could not be created!");
	}

	sceneManager.init();
}

bool App::isRunning() const
{
	return running;
}

void App::shutdown()
{
	Logger::logInfo("Shutting down...");
	running = false;
}

const WindowPtr& App::getWindow() const
{
	return window;
}

const SurfacePtr& App::getWindowSurface() const
{
	return windowSurface;
}
