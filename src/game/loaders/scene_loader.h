#pragma once

#include <array>
#include <memory>
#include "../../engine/scene_manager/scene.h"

enum SceneId
{
	MainMenu,
	GameMap,
	Fight,
	Win,
	Lose
};

class SceneLoader
{
public:
	static std::vector<std::shared_ptr<Scene>> getScenes();

private:
	SceneLoader() = default;
};
