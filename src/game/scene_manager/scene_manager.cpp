#include "scene_manager.h"
#include "../game_map/scene_game_map.h"
#include "../../common/logger.h"

void SceneManager::init()
{
	scenes[SceneId::Blank] = std::make_shared<Scene>();
	scenes[SceneId::GameMap] = std::make_shared<SceneGameMap>();
	currentScene = scenes[SceneId::Blank];
	setNextScene(SceneId::GameMap);
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
