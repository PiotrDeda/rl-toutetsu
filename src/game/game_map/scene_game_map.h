#pragma once

#include "../scene_manager/scene.h"
#include "map.h"

class SceneGameMap : public Scene
{
public:
	void enter() override;
	void doEvents(SDL_Event event) override;
	void doLogic() override;
	void doRender() override;

	[[nodiscard]] const char* getName() const override { return "SceneGameMap"; }

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	Map map;
};
