#include "spell_button.h"

#include "../../engine/app/app.h"
#include "../game_state/game_state.h"

SpellButton::SpellButton(const std::shared_ptr<Camera>& camera) : GameObject(camera) {}

void SpellButton::draw() const
{
	if (enabled && spell)
		spell->sprite->draw(camera->getScreenX(x), camera->getScreenY(y), camera->getScale());
}

bool SpellButton::isMouseOver(int mouseX, int mouseY)
{
	return enabled &&
		   mouseX >= camera->getScreenX(x) &&
		   mouseX <= camera->getScreenX(x) + spell->sprite->getScaledWidth(camera->getScale()) &&
		   mouseY >= camera->getScreenY(y) &&
		   mouseY <= camera->getScreenY(y) + spell->sprite->getScaledHeight(camera->getScale());
}

void SpellButton::onClick()
{
	if (clickable)
	{
		GameState::get().playAttackAnimationOnEnemy();
	}
}
