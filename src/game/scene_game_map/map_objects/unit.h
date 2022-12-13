#pragma once

#include "../../../engine/app/app.h"
#include "../../enemy/enemy.h"
#include "../../game_state/game_state.h"
#include "../../loaders/scene_loader.h"
#include "map_object.h"

class Unit : public MapObject
{
public:
	explicit Unit(const std::shared_ptr<Enemy>& enemy) : MapObject(enemy->sprite), enemy(enemy) {}

	bool onInteract() override
	{
		App::get().sceneManager.setNextScene(SceneId::Fight);
		return false;
	}

private:
	std::shared_ptr<Enemy> enemy;
};
