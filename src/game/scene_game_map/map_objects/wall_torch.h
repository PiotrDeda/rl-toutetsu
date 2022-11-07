#pragma once

#include "../../../engine/app/app.h"
#include "map_object.h"

class WallTorch : public MapObject
{
public:
	explicit WallTorch() : MapObject(App::get().getSprite("wall_torch")) {}
};