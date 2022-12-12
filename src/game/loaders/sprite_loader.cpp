#include "sprite_loader.h"

#include "../../engine/sprite/animated_sprite.h"
#include "../../engine/sprite/animated_state_sprite.h"
#include "../../engine/sprite/state_sprite.h"

std::map<std::string, std::shared_ptr<Sprite>> SpriteLoader::getSprites()
{
	std::map<std::string, std::shared_ptr<Sprite>> sprites;

	// UI
	sprites.emplace("title", std::make_shared<Sprite>("ui/title"));
	sprites.emplace("play_button", std::make_shared<Sprite>("ui/play_button"));
	sprites.emplace("quit_button", std::make_shared<Sprite>("ui/quit_button"));
	sprites.emplace("equipment_bg", std::make_shared<Sprite>("ui/equipment_bg"));
	sprites.emplace("win_screen", std::make_shared<Sprite>("ui/win_screen"));

	// Tiles
	sprites.emplace("player", std::make_shared<AnimatedStateSprite>("tiles/player", 2, 30, 4));
	sprites.emplace("wall", std::make_shared<Sprite>("tiles/wall"));
	sprites.emplace("wall_torch", std::make_shared<AnimatedSprite>("tiles/wall_torch", 3, 100));
	sprites.emplace("floor", std::make_shared<Sprite>("tiles/floor"));
	sprites.emplace("floor_exit", std::make_shared<Sprite>("tiles/floor_exit"));

	// Units
	sprites.emplace("unit_toutetsu", std::make_shared<Sprite>("units/unit_toutetsu"));

	// Items
	sprites.emplace("blank_item", std::make_shared<Sprite>("items/blank_item"));
	sprites.emplace("test_item", std::make_shared<Sprite>("items/test_item"));
	sprites.emplace("test_item_2", std::make_shared<Sprite>("items/test_item_2"));

	return sprites;
}
