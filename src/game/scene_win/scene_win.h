#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"

class SceneWin : public Scene
{
public:
	SceneWin();

	[[nodiscard]] const char* getName() const override { return "SceneWin"; }

	std::shared_ptr<UICamera> camera = std::make_shared<UICamera>();
};
