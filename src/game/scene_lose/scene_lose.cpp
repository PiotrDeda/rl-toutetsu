#include "scene_lose.h"

#include "../../engine/app/app.h"
#include "../scene_main_menu/quit_button.h"

SceneLose::SceneLose() : Scene()
{
	auto loseScreen = std::make_shared<GameObject>(App::get().getSprite("lose_screen"), camera);
	renderables.push_back(loseScreen);

	auto quitButton = std::make_shared<QuitButton>(App::get().getSprite("quit_button"), camera);
	quitButton->setPosition(482, 445);
	renderables.push_back(quitButton);
	clickables.push_back(quitButton);
}
