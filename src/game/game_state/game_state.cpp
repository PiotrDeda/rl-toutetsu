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

void GameState::fight(const std::shared_ptr<Enemy>& enemy)
{
	App::get().sceneManager.setNextScene(SceneId::Fight);
	sceneFight->setEnemy(enemy);
}
