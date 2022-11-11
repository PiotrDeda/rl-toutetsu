#include "scene_fight.h"

#include <utility>
#include "../../engine/app/app.h"

SceneFight::SceneFight(std::shared_ptr<GameState> gameState) : Scene()
{
	this->gameState = std::move(gameState);

	auto uiTestEntity = createUIObject("ui_equipment_bg", 912, 0);
}

std::shared_ptr<GameObject> SceneFight::createUIObject(const std::string& spriteId, int x, int y)
{
	auto object = std::make_shared<GameObject>(App::get().getSprite(spriteId), uiCamera);
	object->move(x, y);
	renderables.push_back(object);
	return object;
}
