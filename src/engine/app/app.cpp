#include "app.h"

#include <stdexcept>
#include "../misc/logger.h"

App::~App()
{
	Logger::logInfo("Quitting SDL...");
	SDL_DestroyWindow(window.get());
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void App::init()
{
	// SDL
	Logger::logInfo("Starting SDL...");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Logger::logErrorSDL("SDL could not initialize!");
		throw std::runtime_error("SDL could not initialize!");
	}

	// Window
	window = makeWindow(SDL_CreateWindow("Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										 defaultWidth, defaultHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
	if (!window)
	{
		Logger::logErrorSDL("Window could not be created!");
		throw std::runtime_error("Window could not be created!");
	}

	// Renderer
	renderer = makeRenderer(SDL_CreateRenderer(window.get(), -1,
											   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if (!renderer)
	{
		Logger::logErrorSDL("Renderer could not be created!");
		throw std::runtime_error("Renderer could not be created!");
	}
	SDL_SetRenderDrawColor(renderer.get(), 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderSetLogicalSize(renderer.get(), defaultWidth, defaultHeight);

	// SDL_Image
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		Logger::logErrorIMG("SDL_image could not initialize!");
		throw std::runtime_error("SDL_image could not initialize!");
	}

	// SDL_TTF
	if (TTF_Init() == -1)
	{
		Logger::logErrorTTF("SDL_ttf could not initialize!");
		throw std::runtime_error("SDL_ttf could not initialize!");
	}

	// Font
	font = makeFont(TTF_OpenFont(App::getAssetPath("consola", "ttf"), 20));
	if (!font)
	{
		Logger::logErrorTTF("Failed to load font");
		throw std::runtime_error("Failed to load font");
	}

	Logger::logInfo("SDL initialized");
}

void App::loadSprites(std::map<std::string, std::shared_ptr<Sprite>> loadedSprites)
{
	sprites = std::move(loadedSprites);
}

int App::run()
{
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_WINDOWEVENT:
					if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
						updateWindowSize();
					break;
				case SDL_QUIT:
					shutdown();
					break;
				default:
					break;
			}
			sceneManager.currentScene->doEvents(event);
		}
		sceneManager.currentScene->doLogic();
		sceneManager.currentScene->doRender();
		sceneManager.switchScenes();
	}

	return 0;
}

void App::shutdown()
{
	Logger::logInfo("Shutting down...");
	running = false;
}

const char* App::getAssetPath(const char* path, const char* fileType)
{
	const char* prefix = assetPath;
	char* result = new char[strlen(prefix) + strlen(path) + strlen(fileType) + 2];
	strcpy(result, prefix);
	strcat(result, path);
	strcat(result, ".");
	strcat(result, fileType);
	return result;
}

std::shared_ptr<Sprite> App::getSprite(const std::string& id) const
{
	if (sprites.find(id) == sprites.end())
	{
		Logger::logError("Sprite not found: %s", id.c_str());
		throw std::runtime_error("Sprite not found: " + id);
	}
	return sprites.at(id);
}

int App::getMouseX() const
{
	int x;
	SDL_GetMouseState(&x, nullptr);
	return static_cast<int>(static_cast<float>(x - widthOffset) * widthMultiplier);
}

int App::getMouseY() const
{
	int y;
	SDL_GetMouseState(nullptr, &y);
	return static_cast<int>(static_cast<float>(y - heightOffset) * heightMultiplier);
}

void App::updateWindowSize()
{
	Logger::logInfo("Updating window size...");
	int w, h;
	SDL_GetWindowSize(window.get(), &w, &h);
	auto fw = static_cast<float>(w), fh = static_cast<float>(h),
			fdw = static_cast<float>(defaultWidth), fdh = static_cast<float>(defaultHeight);
	if (fw / fh > fdw / fdh)
	{
		float newW = fh * fdw / fdh;
		widthOffset = static_cast<int>(fw - newW) / 2;
		heightOffset = 0;
		fw = newW;
	}
	else if (fw / fh < fdw / fdh)
	{
		float newH = fw * fdh / fdw;
		widthOffset = 0;
		heightOffset = static_cast<int>(fh - newH) / 2;
		fh = newH;
	}
	else
	{
		widthOffset = 0;
		heightOffset = 0;
	}
	widthMultiplier = fdw / fw;
	heightMultiplier = fdh / fh;
}
