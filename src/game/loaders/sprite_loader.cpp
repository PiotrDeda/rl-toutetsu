#include "sprite_loader.h"
#include "../../engine/sprite/blank_sprite.h"
#include "../../engine/sprite/animated_sprite.h"
#include "../../engine/sprite/state_sprite.h"
#include "../../engine/sprite/animated_state_sprite.h"

std::map<std::string, std::shared_ptr<Sprite>> SpriteLoader::getSprites()
{
	std::map<std::string, std::shared_ptr<Sprite>> sprites;

	sprites.emplace("blank", std::make_shared<BlankSprite>());

	// Main menu
	sprites.emplace("play_button", std::make_shared<Sprite>("play_button"));
	sprites.emplace("quit_button", std::make_shared<Sprite>("quit_button"));

	// Game map
	sprites.emplace("player", std::make_shared<AnimatedStateSprite>("player", 2, 30, 4));
	sprites.emplace("wall", std::make_shared<Sprite>("wall"));
	sprites.emplace("wall_torch", std::make_shared<AnimatedSprite>("wall_torch", 3, 10));
	sprites.emplace("ui_equipment_bg", std::make_shared<Sprite>("ui_equipment_bg"));

	return sprites;
}
