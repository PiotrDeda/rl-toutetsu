#include "app.h"

#include <stdexcept>
#include <SDL_image.h>

#include "../util/logger.h"

App::~App()
{
	Logger::logInfo("Quitting SDL...");
	SDL_DestroyWindow(window.get());
	IMG_Quit();
	SDL_Quit();
}

void App::init()
{
	// SDL
	Logger::logInfo("Starting SDL...");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Logger::logErrorSdl("SDL could not initialize!");
		throw std::runtime_error("SDL could not initialize!");
	}

	// Window
	window = makeWindow(SDL_CreateWindow("Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										 defaultWidth, defaultHeight, SDL_WINDOW_SHOWN));
	if (!window)
	{
		Logger::logErrorSdl("Window could not be created!");
		throw std::runtime_error("Window could not be created!");
	}

	// Renderer
	renderer = makeRenderer(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));
	if (!renderer)
	{
		Logger::logErrorSdl("Renderer could not be created!");
		throw std::runtime_error("Renderer could not be created!");
	}
	SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);

	// SDL_Image
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
		Logger::logErrorImg("SDL_image could not initialize!");

	// Sprites
	loadSprites();

	// Scene Manager
	sceneManager.init();

	Logger::logInfo("SDL initialized");
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

const char* App::getAssetPath(const char* path)
{
	const char* prefix = assetPath;
	const char* suffix = ".png";
	char* result = new char[strlen(prefix) + strlen(path) + strlen(suffix) + 1];
	strcpy(result, prefix);
	strcat(result, path);
	strcat(result, suffix);
	return result;
}

std::shared_ptr<Sprite> App::getSprite(const std::string& id) const
{
	if (sprites.find(id) == sprites.end())
	{
		Logger::logError("Sprite not found: %s", id.c_str());
		throw std::runtime_error("Sprite not found: " + id);
	}
	return std::make_shared<Sprite>(sprites.at(id));
}

void App::loadSprites()
{
	sprites.emplace("player", Sprite("player"));
	sprites.emplace("wall", Sprite("wall"));
	sprites.emplace("wall_torch", Sprite("wall_torch"));
}


