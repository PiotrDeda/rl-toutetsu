#pragma once

#include "../../../engine/app/app.h"
#include "map_object.h"

class Wall : public MapObject
{
public:
	Wall() : MapObject(App::get().getSprite("wall")) {}
};