#include "scene_loader.h"

#include "../scene_fight/scene_fight.h"
#include "../scene_game_map/scene_game_map.h"
#include "../scene_main_menu/scene_main_menu.h"

std::vector<std::shared_ptr<Scene>> SceneLoader::getScenes()
{
	static std::shared_ptr<GameState> gameState = std::make_shared<GameState>();
	static std::vector<std::shared_ptr<Scene>> scenes = {
		std::make_shared<SceneMainMenu>(),
		std::make_shared<SceneGameMap>(gameState),
		std::make_shared<SceneFight>(gameState)
	};
	return scenes;
}
