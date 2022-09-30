#pragma once

#include "scene.h"
#include "../../game/loaders/scene_loader.h"

class SceneManager
{
public:
	void loadScenes(std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> loadedScenes);
	void setNextScene(SceneId nextSceneId);
	void switchScenes();

	std::shared_ptr<Scene> currentScene;

private:
	std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> scenes;
	std::shared_ptr<Scene> nextScene;
};
