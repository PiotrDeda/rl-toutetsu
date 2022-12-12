#include "scene_loader.h"

#include "../game_state/game_state.h"
#include "../scene_fight/scene_fight.h"
#include "../scene_game_map/scene_game_map.h"
#include "../scene_main_menu/scene_main_menu.h"

std::vector<std::shared_ptr<Scene>> SceneLoader::getScenes()
{
	auto sceneMainMenu = std::make_shared<SceneMainMenu>();
	auto sceneGameMap = std::make_shared<SceneGameMap>();
	auto sceneFight = std::make_shared<SceneFight>();

	GameState::get().sceneGameMap = sceneGameMap;
	GameState::get().sceneFight = sceneFight;

	return {sceneMainMenu, sceneGameMap, sceneFight};
}
