#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "map.h"

class SceneGameMap : public Scene
{
public:
	SceneGameMap();

	void handleEvent(Event event) override;
	void nextLevel();

	[[nodiscard]] const char* getName() const override { return "SceneGameMap"; }

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
	std::shared_ptr<Map> map;
	int currentLevel = 0;

private:
	std::shared_ptr<GameObject> createUIObject(const std::string& spriteId, int x, int y);
};
