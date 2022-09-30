#include "play_button.h"
#include "../../engine/app/app.h"

PlayButton::PlayButton(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera) : GameObject(
		sprite, camera) {}

void PlayButton::onClick()
{
	App::get().sceneManager.setNextScene(SceneId::GameMap);
}
