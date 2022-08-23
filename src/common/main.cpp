#include <SDL.h>
#include "app.h"

int main(int, char* [])
{
	auto& app = App::get();
	app.init();
	auto& sceneManager = app.sceneManager;

	while (app.isRunning())
	{
		// Events
		SDL_Event event;
		while (SDL_PollEvent(&event))
			sceneManager.currentScene->doEvents(event);

		// Logic
		sceneManager.currentScene->doLogic();

		// Render
		sceneManager.currentScene->doRender();

		// Scenes
		sceneManager.switchScenes();
	}

	return 0;
}
