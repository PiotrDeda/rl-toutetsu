#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu();

	[[nodiscard]] const char* getName() const override { return "SceneMainMenu"; }

	std::shared_ptr<UICamera> camera = std::make_shared<UICamera>();
};
