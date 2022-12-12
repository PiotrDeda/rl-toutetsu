#pragma once

#include "../../../engine/game_object/game_object.h"

class MapObject : public GameObject
{
public:
	explicit MapObject(const std::shared_ptr<Sprite> &sprite) : GameObject(sprite, nullptr) {}

	void draw() const override {}

	virtual bool onInteract() { return false; }

	[[nodiscard]] bool isMouseOver(int mouseX, int mouseY) override { return false; }
};
