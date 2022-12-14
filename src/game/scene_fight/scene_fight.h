#pragma once

#include "../../engine/camera/ui_camera.h"
#include "../../engine/scene_manager/scene.h"
#include "../enemy/enemy_data.h"
#include "../game_state/inventory.h"
#include "spell_button.h"

class SceneFight : public Scene
{
public:
	SceneFight();

	void handleEvent(Event event) override;
	void setupFight(const std::shared_ptr<EnemyData>& enemyData, const std::shared_ptr<Inventory>& inventory);
	void changeTurn();
	static Uint32 endEnemyTurn(Uint32, void* object);

	[[nodiscard]] const char* getName() const override { return "SceneFight"; }

	std::shared_ptr<UICamera> uiCamera = std::make_shared<UICamera>();
	std::vector<std::shared_ptr<SpellButton>> spellButtons;
	std::shared_ptr<GameObject> enemySprite;
	bool playersTurn = true;
};
