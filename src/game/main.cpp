#include <SDL.h>
#include "../engine/app/app.h"
#include "loaders/sprite_loader.h"

int main(int, char* [])
{
	auto& app = App::get();
	app.init();
	app.loadSprites(SpriteLoader::getSprites());
	auto& sceneManager = app.sceneManager;
	sceneManager.loadScenes(SceneLoader::getScenes());

	while (app.isRunning())
	{
		// Events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			app.doEvents(event);
			sceneManager.currentScene->doEvents(event);
		}

		// Logic
		sceneManager.currentScene->doLogic();

		// Render
		sceneManager.currentScene->doRender();

		// Scenes
		sceneManager.switchScenes();
	}

	return 0;
}
