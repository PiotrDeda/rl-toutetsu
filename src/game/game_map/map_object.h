#pragma once

#include "../../engine/game_object/game_object.h"

class MapObject : public GameObject
{
public:
	MapObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera);
};