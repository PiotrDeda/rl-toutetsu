#pragma once

#include "../../../engine/app/app.h"
#include "map_object.h"

class PlayerPuppet : public MapObject
{
public:
	PlayerPuppet() : MapObject(App::get().getSprite("player")) {}
};