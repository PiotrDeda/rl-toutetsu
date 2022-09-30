#include "scene_main_menu.h"
#include "../../engine/app/app.h"
#include "play_button.h"
#include "quit_button.h"

SceneMainMenu::SceneMainMenu() : Scene()
{
	auto playButton = std::make_shared<PlayButton>(App::get().getSprite("play_button"), camera);
	playButton->move(64, 64);
	renderables.push_back(playButton);
	clickables.push_back(playButton);

	auto quitButton = std::make_shared<QuitButton>(App::get().getSprite("quit_button"), camera);
	quitButton->move(64, 192);
	renderables.push_back(quitButton);
	clickables.push_back(quitButton);
}
