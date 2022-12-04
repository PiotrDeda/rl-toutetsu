#pragma once

#include "../../../engine/game_object/game_object.h"
#include "../../game_state/game_state.h"

class MapObject : public GameObject
{
public:
	explicit MapObject(const std::shared_ptr<Sprite>& sprite) : GameObject(sprite, nullptr) {}

	void draw() const override {}

	virtual void onInteract(const std::shared_ptr<GameState>& gameState) {}

	[[nodiscard]] bool isMouseOver(int mouseX, int mouseY) override { return false; }
};
