#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../game_state/game_state.h"

class SceneFight : public Scene
{
public:
	explicit SceneFight(std::shared_ptr<GameState> gameState);

	[[nodiscard]] const char* getName() const override { return "SceneFight"; }

	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
	std::shared_ptr<GameState> gameState;

private:
	std::shared_ptr<GameObject> createUIObject(const std::string& spriteId, int x, int y);
};
