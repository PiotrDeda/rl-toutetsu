#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../game_state/game_state.h"
#include "map.h"

class SceneGameMap : public Scene
{
public:
	explicit SceneGameMap(const std::shared_ptr<GameState>& gameState);

	void customEvents(SDL_Event event) override;
	void customLogic() override;

	[[nodiscard]] const char* getName() const override { return "SceneGameMap"; }

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
	std::shared_ptr<Map> map = std::make_shared<Map>(40);
	std::shared_ptr<GameState> gameState;

private:
	std::shared_ptr<MapObject> createMapObject(const std::string& spriteId, int x, int y);
	std::shared_ptr<GameObject> createUIObject(const std::string& spriteId, int x, int y);
};
