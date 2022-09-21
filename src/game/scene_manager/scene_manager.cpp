#include "scene_manager.h"
#include "../game_map/scene_game_map.h"
#include "../../common/logger.h"
#include "../main_menu/scene_main_menu.h"

void SceneManager::init()
{
	scenes[SceneId::Blank] = std::make_shared<Scene>();
	scenes[SceneId::MainMenu] = std::make_shared<SceneMainMenu>();
	scenes[SceneId::GameMap] = std::make_shared<SceneGameMap>();
	currentScene = scenes[SceneId::Blank];
	setNextScene(SceneId::MainMenu);
}

void SceneManager::setNextScene(SceneId nextSceneId)
{
	nextScene = scenes[nextSceneId];
	Logger::logInfo("Switching from %s to %s...", currentScene->getName(), nextScene->getName());
}

void SceneManager::switchScenes()
{
	if (currentScene != nextScene)
	{
		currentScene = nextScene;
		//currentScene->enter();
	}
}
