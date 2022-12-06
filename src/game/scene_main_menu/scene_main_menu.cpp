#include "scene_main_menu.h"

#include "../../engine/app/app.h"
#include "quit_button.h"
#include "play_button.h"

SceneMainMenu::SceneMainMenu() : Scene()
{
	auto title = std::make_shared<GameObject>(App::get().getSprite("title"), camera);
	title->setPosition(482, 64);
	renderables.push_back(title);

	auto playButton = std::make_shared<PlayButton>(App::get().getSprite("play_button"), camera);
	playButton->setPosition(482, 317);
	renderables.push_back(playButton);
	clickables.push_back(playButton);

	auto quitButton = std::make_shared<QuitButton>(App::get().getSprite("quit_button"), camera);
	quitButton->setPosition(482, 445);
	renderables.push_back(quitButton);
	clickables.push_back(quitButton);
}
