#include "scene_loader.h"
#include "../main_menu/scene_main_menu.h"
#include "../game_map/scene_game_map.h"

std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> SceneLoader::getScenes()
{
	std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> scenes;
	scenes[SceneId::MainMenu] = std::make_shared<SceneMainMenu>();
	scenes[SceneId::GameMap] = std::make_shared<SceneGameMap>();
	return scenes;
}
