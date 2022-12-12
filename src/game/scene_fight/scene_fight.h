#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../game_state/game_state.h"

class SceneFight : public Scene
{
public:
	SceneFight();

	void handleEvent(Event event) override;

	[[nodiscard]] const char* getName() const override { return "SceneFight"; }

	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();

private:
	std::shared_ptr<GameObject> createUIObject(const std::string& spriteId, int x, int y);
};
