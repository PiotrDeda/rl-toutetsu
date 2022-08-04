#pragma once

#include "../engine/scene.h"

class SceneMainMenu : public Scene
{
public:
	void enter() override;
	void doEvents(SDL_Event event) override;
	void doLogic() override;

	int speed = 1, delay = 0;
};
