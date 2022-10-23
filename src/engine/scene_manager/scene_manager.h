#pragma once

#include "scene.h"

class SceneManager
{
public:
	void loadScenes(std::vector<std::shared_ptr<Scene>> loadedScenes);
	void setNextScene(int nextSceneId);
	void switchScenes();

	std::shared_ptr<Scene> currentScene;

private:
	std::vector<std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> nextScene;
};
