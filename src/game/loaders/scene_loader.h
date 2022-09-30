#pragma once

#include <array>
#include <memory>
#include "../../engine/scene_manager/scene.h"

enum SceneId
{
	MainMenu,
	GameMap
};

class SceneLoader
{
public:
	static constexpr int sceneCount = 8;

	static std::array<std::shared_ptr<Scene>, sceneCount> getScenes();

private:
	SceneLoader() = default;
};
