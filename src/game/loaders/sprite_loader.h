#pragma once

#include <map>
#include <memory>
#include <string>
#include "../../engine/sprite/sprite.h"

class SpriteLoader
{
public:
	static std::map<std::string, std::shared_ptr<Sprite>> getSprites();

private:
	SpriteLoader() = default;
};
