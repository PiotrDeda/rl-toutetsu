#include "game_state.h"

void GameState::setSceneGameMap(const std::shared_ptr<SceneGameMap>& scene)
{
	this->sceneGameMap = scene;
}

void GameState::setSceneFight(const std::shared_ptr<SceneFight>& scene)
{
	this->sceneFight = scene;
}

void GameState::nextLevel()
{
	sceneGameMap->nextLevel();
}

void GameState::startFight(const std::shared_ptr<EnemyData>& enemyData)
{
	App::get().sceneManager.setNextScene(SceneId::Fight);
	sceneFight->setupFight(enemyData, inventory);
}

void GameState::changeTurn()
{
	sceneFight->changeTurn();
}