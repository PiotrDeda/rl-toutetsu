#pragma once

#include <map>
#include <string>
#include <memory>
#include "../../engine/sprite/sprite.h"

class SpriteLoader
{
public:
	static std::map<std::string, std::shared_ptr<Sprite>> getSprites();

private:
	SpriteLoader() = default;
};
