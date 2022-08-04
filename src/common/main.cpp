#include <SDL.h>
#include "app.h"

int main(int, char* [])
{
	App::get().init();

	while (App::get().isRunning())
	{
		// Events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			App::get().sceneManager.currentScene->doEvents(event);
		}

		// Logic
		App::get().sceneManager.currentScene->doLogic();

		// Render
		App::get().sceneManager.currentScene->doRender();
		SDL_UpdateWindowSurface(App::get().getWindow().get());

		// Scenes
		App::get().sceneManager.switchScenes();
	}

	return 0;
}
