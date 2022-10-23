#include <SDL.h>
#include "../engine/app/app.h"
#include "loaders/scene_loader.h"
#include "loaders/sprite_loader.h"

int main(int, char* [])
{
	auto& app = App::get();
	app.init();
	app.loadSprites(SpriteLoader::getSprites());
	app.sceneManager.loadScenes(SceneLoader::getScenes());
	return app.run();
}
