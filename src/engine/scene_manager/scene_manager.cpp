#include "scene_manager.h"
#include <utility>
#include "../misc/logger.h"

void SceneManager::loadScenes(std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> loadedScenes)
{
	this->scenes = std::move(loadedScenes);
	currentScene = scenes[0];
	nextScene = scenes[0];
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
