#include "scene_win.h"

#include "../../engine/app/app.h"
#include "../scene_main_menu/quit_button.h"

SceneWin::SceneWin() : Scene()
{
	auto winScreen = std::make_shared<GameObject>(App::get().getSprite("win_screen"), camera);
	renderables.push_back(winScreen);

	auto quitButton = std::make_shared<QuitButton>(App::get().getSprite("quit_button"), camera);
	quitButton->setPosition(482, 445);
	renderables.push_back(quitButton);
	clickables.push_back(quitButton);
}
