#include "text_object.h"
#include "../sprite/text_sprite.h"

TextObject::TextObject(const char* initialText, const std::shared_ptr<Camera>& camera) : GameObject(camera)
{
	this->text = initialText;
	this->sprite = std::make_shared<TextSprite>(initialText);
}

const char* TextObject::getText()
{
	return text;
}

void TextObject::setText(const char* newText)
{
	text = newText;
	sprite->setText(text);
}
