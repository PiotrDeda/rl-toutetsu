#include "scene_manager.h"
#include "../game/scene_main_menu.h"
#include "../util/logger.h"

void SceneManager::init()
{
	scenes[SceneId::Blank] = std::make_shared<Scene>();
	scenes[SceneId::MainMenu] = std::make_shared<SceneMainMenu>();
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
		currentScene->enter();
	}
}
