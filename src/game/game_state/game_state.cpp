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

void GameState::doPlayerAttack(const std::shared_ptr<ItemData>& spell)
{
	sceneFight->lockSpells();
	sceneFight->enemyStats.maxHP = GameState::get().playerStats->dealDamage(spell->getSpellStats(), sceneFight->enemyStats);
	sceneFight->attackAnimationEnemy->sprite->play(SceneFight::changeTurnCallback, sceneFight.get());
}

void GameState::doEnemyAttack()
{
	playerStats->takeDamage(sceneFight->enemyStats);
	sceneFight->attackAnimationPlayer->sprite->play(SceneFight::changeTurnCallback, sceneFight.get());
}

void GameState::healPlayer()
{
	playerStats->currentHp = playerStats->currentStats.maxHP;
	playerStats->refreshText();
}
