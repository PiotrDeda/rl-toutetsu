#pragma once

#include "game_object.h"

class TextObject : public GameObject
{
public:
	TextObject(const char* initialText, const std::shared_ptr<Camera>& camera);

	const char* getText();
	void setText(const char* text);

private:
	const char* text;
};
