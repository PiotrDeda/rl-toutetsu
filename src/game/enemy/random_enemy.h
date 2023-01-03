#pragma once

#include "enemies.h"
#include "../game_state/game_state.h"

class RandomEnemy
{
public:
	SINGLETON(RandomEnemy)

	std::shared_ptr<EnemyData> generate(std::mt19937& gen)
	{
		std::uniform_int_distribution<> percentageDistr(0, 99);
		int tier = getTier(GameState::get().currentLevel, percentageDistr(gen));
		std::uniform_int_distribution<> enemyDistr(0, static_cast<int>(enemies[tier].size() - 1));
		std::shared_ptr<EnemyData> enemy = enemies[tier][enemyDistr(gen)]->generate();
		return enemy;
	}

	static int getTier(int currentLevel, int tierPercentage)
	{
		switch (currentLevel)
		{
			case 1:
				if (tierPercentage < 80)
					return 1;
				else if (tierPercentage < 99)
					return 2;
				else
					return 3;
			case 2:
				if (tierPercentage < 10)
					return 1;
				else if (tierPercentage < 90)
					return 2;
				else if (tierPercentage < 99)
					return 3;
				else
					return 4;
			case 3:
				if (tierPercentage < 1)
					return 1;
				else if (tierPercentage < 10)
					return 2;
				else if (tierPercentage < 90)
					return 3;
				else
					return 4;
			case 4:
				if (tierPercentage < 1)
					return 2;
				else if (tierPercentage < 20)
					return 3;
				else
					return 4;
			default:
				return 4;
		}
	}

private:
	RandomEnemy() = default;

	std::vector<std::vector<std::shared_ptr<RandomEnemyTemplate>>> enemies = {
			{},
			{
					std::make_shared<GreenSlime>(),
					std::make_shared<BlueBeholder>(),
			},
			{
					std::make_shared<BlueSlime>(),
					std::make_shared<OrangeBeholder>(),
			},
			{
					std::make_shared<PurpleSlime>(),
					std::make_shared<PinkBeholder>(),
			},
			{
					std::make_shared<FireSlime>(),
					std::make_shared<LavaBeholder>(),
			}
	};
};
