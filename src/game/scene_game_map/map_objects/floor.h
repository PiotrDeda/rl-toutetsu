#pragma once

#include "../../../engine/app/app.h"
#include "map_object.h"

class Floor : public MapObject
{
public:
	Floor() : MapObject(App::get().getSprite("floor")) {}
};