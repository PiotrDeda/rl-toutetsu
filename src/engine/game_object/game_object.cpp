#include "game_object.h"

GameObject::GameObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera)
{
	this->sprite = sprite;
	this->camera = camera;
}

void GameObject::draw() const
{
	if (enabled)
		sprite->draw(camera->getScreenX(x), camera->getScreenY(y), camera->getScale());
}

void GameObject::setPosition(const int targetX, const int targetY)
{
	x = targetX;
	y = targetY;
}

int GameObject::getX() const
{
	return x;
}

int GameObject::getY() const
{
	return y;
}

bool GameObject::isMouseOver(int mouseX, int mouseY)
{
	return enabled &&
		   mouseX >= camera->getScreenX(x) &&
		   mouseX <= camera->getScreenX(x) + sprite->getScaledWidth(camera->getScale()) &&
		   mouseY >= camera->getScreenY(y) &&
		   mouseY <= camera->getScreenY(y) + sprite->getScaledHeight(camera->getScale());
}

void GameObject::onClick() {}

GameObject::GameObject(const std::shared_ptr<Camera>& camera)
{
	this->camera = camera;
}
