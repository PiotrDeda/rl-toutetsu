#pragma once

#include "equippable_items.h"
#include "test_item.h"

class RandomItem
{
public:
	SINGLETON(RandomItem)

	std::shared_ptr<ItemData> generate(std::mt19937& gen, int currentLevel)
	{
		std::uniform_int_distribution<> percentageDistr(0, 99);
		int tier = getTier(currentLevel, percentageDistr(gen));
		std::uniform_int_distribution<> itemDistr(0, static_cast<int>(items[tier].size() - 1));
		std::shared_ptr<ItemData> item = items[tier][itemDistr(gen)]->generate();
		return item;
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
	RandomItem() = default;

	std::vector<std::vector<std::shared_ptr<EquippableItemTemplate>>> items = {
			{},
			{
					std::make_shared<WoodenWand>(),
					std::make_shared<WoodenSword>(),
					std::make_shared<WoodenAxe>(),
					std::make_shared<WoodenStaff>(),
					std::make_shared<CritPendant>(),
					std::make_shared<WhiteShield>(),
					std::make_shared<BlackShield>(),
			},
			{
					std::make_shared<IronWand>(),
					std::make_shared<IronSword>(),
					std::make_shared<IronAxe>(),
					std::make_shared<IronStaff>(),
					std::make_shared<IronHelmet>(),
					std::make_shared<IronArmor>(),
					std::make_shared<IronBoots>(),
					std::make_shared<HealthPendant>(),
					std::make_shared<WhiteShield>(),
					std::make_shared<BlackShield>(),
					std::make_shared<WhiteBookI>(),
					std::make_shared<BlackBookI>(),
			},
			{
					std::make_shared<GoldenWand>(),
					std::make_shared<GoldenSword>(),
					std::make_shared<GoldenAxe>(),
					std::make_shared<GoldenStaff>(),
					std::make_shared<GoldenHelmet>(),
					std::make_shared<GoldenArmor>(),
					std::make_shared<GoldenBoots>(),
					std::make_shared<GreaterHealthPendant>(),
					std::make_shared<WhiteBookII>(),
					std::make_shared<BlackBookII>(),
			},
			{
					std::make_shared<EnchantedWand>(),
					std::make_shared<EnchantedSword>(),
					std::make_shared<EnchantedAxe>(),
					std::make_shared<EnchantedStaff>(),
					std::make_shared<EnchantedHelmet>(),
					std::make_shared<EnchantedArmor>(),
					std::make_shared<EnchantedBoots>(),
					std::make_shared<AgilityPendant>(),
					std::make_shared<WhiteBookIII>(),
					std::make_shared<BlackBookIII>(),
			}
	};
};
