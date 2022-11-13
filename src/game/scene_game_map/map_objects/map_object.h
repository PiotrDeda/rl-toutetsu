#pragma once

#include "../../../engine/game_object/game_object.h"

class MapObject : public GameObject
{
public:
	explicit MapObject(const std::shared_ptr<Sprite>& sprite) : GameObject(sprite, nullptr) {}

	void draw() const override {}

	[[nodiscard]] bool isMouseOver(int mouseX, int mouseY) override { return false; }
};
