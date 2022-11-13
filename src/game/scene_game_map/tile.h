#pragma once

#include <vector>
#include "../../engine/game_object/game_object.h"
#include "../../engine/game_object/i_renderable.h"
#include "map_objects/map_object.h"

class Tile : public GameObject
{
public:
	Tile() : GameObject(nullptr, nullptr) {}

	void draw() const override;
	void draw(const std::shared_ptr<Camera>& camera) const;
	[[nodiscard]] bool isMouseOver(int mouseX, int mouseY) override;
	void setObject(const std::shared_ptr<MapObject>& newObject);

	std::shared_ptr<GameObject> object;
};
