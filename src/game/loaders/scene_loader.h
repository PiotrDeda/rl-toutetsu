#pragma once

#include <array>
#include <memory>
#include "../../engine/scene_manager/scene.h"

enum SceneId
{
	MainMenu,
	GameMap,
	Fight
};

class SceneLoader
{
public:
	static constexpr int sceneCount = 4;

	static std::array<std::shared_ptr<Scene>, sceneCount> getScenes();

private:
	SceneLoader() = default;
};
