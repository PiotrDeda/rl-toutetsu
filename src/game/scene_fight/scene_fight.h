#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../enemy/enemy.h"

class SceneFight : public Scene
{
public:
	SceneFight();

	void handleEvent(Event event) override;
	void setEnemy(const std::shared_ptr<Enemy>& enemy);

	[[nodiscard]] const char* getName() const override { return "SceneFight"; }

	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
};
