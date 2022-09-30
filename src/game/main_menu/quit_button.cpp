#include "quit_button.h"
#include "../../engine/app/app.h"

QuitButton::QuitButton(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera) : GameObject(
		sprite, camera) {}

void QuitButton::onClick()
{
	App::get().shutdown();
}
