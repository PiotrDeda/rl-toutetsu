#pragma once

#include "../scene_manager/scene.h"
#include "../camera/ui_camera.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu();

	[[nodiscard]] const char* getName() const override { return "SceneMainMenu"; }

	std::shared_ptr<UICamera> camera = std::make_shared<UICamera>();
};
