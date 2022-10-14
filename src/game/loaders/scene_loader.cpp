#include "scene_loader.h"
#include "../scene_main_menu/scene_main_menu.h"
#include "../scene_game_map/scene_game_map.h"
#include "../scene_fight/scene_fight.h"

std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> SceneLoader::getScenes()
{
	std::array<std::shared_ptr<Scene>, SceneLoader::sceneCount> scenes;
	std::shared_ptr<GameState> gameState = std::make_shared<GameState>();
	scenes[SceneId::MainMenu] = std::make_shared<SceneMainMenu>();
	scenes[SceneId::GameMap] = std::make_shared<SceneGameMap>(gameState);
	scenes[SceneId::Fight] = std::make_shared<SceneFight>(gameState);
	return scenes;
}
