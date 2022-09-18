#pragma once

#include "../game_object.h"

class PlayButton : public GameObject
{
public:
	PlayButton(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);

	void onClick() override;
};
