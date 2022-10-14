#pragma once

#include "../../engine/game_object/game_object.h"

class QuitButton : public GameObject
{
public:
	QuitButton(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);

	void onClick() override;
};
