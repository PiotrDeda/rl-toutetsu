#pragma once

#include "scene.h"

enum SceneId
{
	Blank = 0,
	MainMenu = 1
};

class SceneManager
{
public:
	void init();
	void setNextScene(SceneId nextSceneId);
	void switchScenes();

	std::shared_ptr<Scene> currentScene;

private:
	std::array<std::shared_ptr<Scene>, 8> scenes;
	std::shared_ptr<Scene> nextScene;
};
