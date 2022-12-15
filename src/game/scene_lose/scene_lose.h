#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"

class SceneLose : public Scene
{
public:
	SceneLose();

	[[nodiscard]] const char* getName() const override { return "SceneLose"; }

	std::shared_ptr<UICamera> camera = std::make_shared<UICamera>();
};
