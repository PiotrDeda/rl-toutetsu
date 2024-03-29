#include "sprite_loader.h"

#include "../../engine/sprite/animated_sprite.h"
#include "../../engine/sprite/animated_state_sprite.h"
#include "../../engine/sprite/playable_sprite.h"

std::map<std::string, std::shared_ptr<Sprite>> SpriteLoader::getSprites()
{
	std::map<std::string, std::shared_ptr<Sprite>> sprites;

	// UI
	sprites.emplace("title", std::make_shared<Sprite>("ui/title"));
	sprites.emplace("play_button", std::make_shared<Sprite>("ui/play_button"));
	sprites.emplace("quit_button", std::make_shared<Sprite>("ui/quit_button"));
	sprites.emplace("equipment_bg", std::make_shared<Sprite>("ui/equipment_bg"));
	sprites.emplace("win_screen", std::make_shared<Sprite>("ui/win_screen"));
	sprites.emplace("lose_screen", std::make_shared<Sprite>("ui/lose_screen"));
	sprites.emplace("player_fight", std::make_shared<AnimatedStateSprite>("tiles/player", 2, 30, 4));
	sprites.emplace("fight_bg", std::make_shared<Sprite>("ui/fight_bg"));
	sprites.emplace("attack_animation_player", std::make_shared<PlayableSprite>("ui/attack_animation", 3, 100));
	sprites.emplace("attack_animation_enemy", std::make_shared<PlayableSprite>("ui/attack_animation", 3, 100));

	// Tiles
	sprites.emplace("player", std::make_shared<AnimatedStateSprite>("tiles/player", 2, 30, 4));
	sprites.emplace("wall", std::make_shared<Sprite>("tiles/wall"));
	sprites.emplace("wall_torch", std::make_shared<AnimatedSprite>("tiles/wall_torch", 3, 100));
	sprites.emplace("floor", std::make_shared<Sprite>("tiles/floor"));
	sprites.emplace("floor_exit", std::make_shared<Sprite>("tiles/floor_exit"));

	// Enemies
	sprites.emplace("green_slime", std::make_shared<Sprite>("enemies/green_slime"));
	sprites.emplace("blue_slime", std::make_shared<Sprite>("enemies/blue_slime"));
	sprites.emplace("purple_slime", std::make_shared<Sprite>("enemies/purple_slime"));
	sprites.emplace("fire_slime", std::make_shared<Sprite>("enemies/fire_slime"));

	sprites.emplace("blue_beholder", std::make_shared<Sprite>("enemies/blue_beholder"));
	sprites.emplace("orange_beholder", std::make_shared<Sprite>("enemies/orange_beholder"));
	sprites.emplace("pink_beholder", std::make_shared<Sprite>("enemies/pink_beholder"));
	sprites.emplace("lava_beholder", std::make_shared<Sprite>("enemies/lava_beholder"));

	sprites.emplace("toutetsu_map", std::make_shared<Sprite>("enemies/toutetsu_map"));
	sprites.emplace("toutetsu_fight", std::make_shared<Sprite>("enemies/toutetsu_fight"));

	// Items
	sprites.emplace("blank_item", std::make_shared<Sprite>("items/blank_item"));

	sprites.emplace("wooden_wand", std::make_shared<Sprite>("items/wooden_wand"));
	sprites.emplace("iron_wand", std::make_shared<Sprite>("items/iron_wand"));
	sprites.emplace("golden_wand", std::make_shared<Sprite>("items/golden_wand"));
	sprites.emplace("enchanted_wand", std::make_shared<Sprite>("items/enchanted_wand"));

	sprites.emplace("wooden_sword", std::make_shared<Sprite>("items/wooden_sword"));
	sprites.emplace("iron_sword", std::make_shared<Sprite>("items/iron_sword"));
	sprites.emplace("golden_sword", std::make_shared<Sprite>("items/golden_sword"));
	sprites.emplace("enchanted_sword", std::make_shared<Sprite>("items/enchanted_sword"));

	sprites.emplace("wooden_axe", std::make_shared<Sprite>("items/wooden_axe"));
	sprites.emplace("iron_axe", std::make_shared<Sprite>("items/iron_axe"));
	sprites.emplace("golden_axe", std::make_shared<Sprite>("items/golden_axe"));
	sprites.emplace("enchanted_axe", std::make_shared<Sprite>("items/enchanted_axe"));

	sprites.emplace("wooden_staff", std::make_shared<Sprite>("items/wooden_staff"));
	sprites.emplace("iron_staff", std::make_shared<Sprite>("items/iron_staff"));
	sprites.emplace("golden_staff", std::make_shared<Sprite>("items/golden_staff"));
	sprites.emplace("enchanted_staff", std::make_shared<Sprite>("items/enchanted_staff"));

	sprites.emplace("iron_helmet", std::make_shared<Sprite>("items/iron_helmet"));
	sprites.emplace("golden_helmet", std::make_shared<Sprite>("items/golden_helmet"));
	sprites.emplace("enchanted_helmet", std::make_shared<Sprite>("items/enchanted_helmet"));

	sprites.emplace("iron_armor", std::make_shared<Sprite>("items/iron_armor"));
	sprites.emplace("golden_armor", std::make_shared<Sprite>("items/golden_armor"));
	sprites.emplace("enchanted_armor", std::make_shared<Sprite>("items/enchanted_armor"));

	sprites.emplace("iron_boots", std::make_shared<Sprite>("items/iron_boots"));
	sprites.emplace("golden_boots", std::make_shared<Sprite>("items/golden_boots"));
	sprites.emplace("enchanted_boots", std::make_shared<Sprite>("items/enchanted_boots"));

	sprites.emplace("crit_pendant", std::make_shared<Sprite>("items/crit_pendant"));
	sprites.emplace("health_pendant", std::make_shared<Sprite>("items/health_pendant"));
	sprites.emplace("greater_health_pendant", std::make_shared<Sprite>("items/greater_health_pendant"));
	sprites.emplace("agility_pendant", std::make_shared<Sprite>("items/agility_pendant"));

	sprites.emplace("white_shield", std::make_shared<Sprite>("items/white_shield"));
	sprites.emplace("black_shield", std::make_shared<Sprite>("items/black_shield"));

	sprites.emplace("white_book_i", std::make_shared<Sprite>("items/white_book_i"));
	sprites.emplace("white_book_ii", std::make_shared<Sprite>("items/white_book_ii"));
	sprites.emplace("white_book_iii", std::make_shared<Sprite>("items/white_book_iii"));
	sprites.emplace("black_book_i", std::make_shared<Sprite>("items/black_book_i"));
	sprites.emplace("black_book_ii", std::make_shared<Sprite>("items/black_book_ii"));
	sprites.emplace("black_book_iii", std::make_shared<Sprite>("items/black_book_iii"));

	sprites.emplace("spell_weapon", std::make_shared<Sprite>("items/spell_weapon"));

	sprites.emplace("spell_zap", std::make_shared<Sprite>("items/spell_zap"));
	sprites.emplace("spell_burn", std::make_shared<Sprite>("items/spell_burn"));
	sprites.emplace("spell_arrow", std::make_shared<Sprite>("items/spell_arrow"));

	sprites.emplace("spell_holy_strike", std::make_shared<Sprite>("items/spell_holy_strike"));
	sprites.emplace("spell_keystone", std::make_shared<Sprite>("items/spell_keystone"));
	sprites.emplace("spell_dark_orb", std::make_shared<Sprite>("items/spell_dark_orb"));

	sprites.emplace("spell_star_shower", std::make_shared<Sprite>("items/spell_star_shower"));
	sprites.emplace("spell_water_gun", std::make_shared<Sprite>("items/spell_water_gun"));
	sprites.emplace("spell_poison", std::make_shared<Sprite>("items/spell_poison"));

	sprites.emplace("spell_sunray", std::make_shared<Sprite>("items/spell_sunray"));
	sprites.emplace("spell_elemental_seal", std::make_shared<Sprite>("items/spell_elemental_seal"));
	sprites.emplace("spell_darkness", std::make_shared<Sprite>("items/spell_darkness"));

	return sprites;
}
