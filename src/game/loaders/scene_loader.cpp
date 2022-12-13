#include "scene_loader.h"

#include "../game_state/game_state.h"
#include "../scene_main_menu/scene_main_menu.h"
#include "../scene_win/scene_win.h"

std::vector<std::shared_ptr<Scene>> SceneLoader::getScenes()
{
	auto sceneMainMenu = std::make_shared<SceneMainMenu>();
	auto sceneGameMap = std::make_shared<SceneGameMap>();
	auto sceneFight = std::make_shared<SceneFight>();
	auto sceneWin = std::make_shared<SceneWin>();

	GameState::get().setSceneGameMap(sceneGameMap);
	GameState::get().setSceneFight(sceneFight);

	return {sceneMainMenu, sceneGameMap, sceneFight, sceneWin};
}
