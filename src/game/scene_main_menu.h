#pragma once

#include "../engine/scene.h"
#include "map.h"

class SceneMainMenu : public Scene
{
public:
	void enter() override;
	void doEvents(SDL_Event event) override;
	void doLogic() override;
	void doRender() override;

	[[nodiscard]] const char* getName() const override { return "SceneMainMenu"; }

	Map map;
};
