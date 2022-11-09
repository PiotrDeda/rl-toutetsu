#pragma once

#include <SDL_keycode.h>
#include <map>
#include <string_view>

class InputManager
{
public:
	std::string_view getInputEvent(SDL_Keycode keycode);
	void assignInputEvent(SDL_Keycode keycode, std::string_view inputEvent);
	void removeInputEvent(std::string_view inputEvent);

private:
	std::map<SDL_Keycode, std::string_view> inputEvents;
};
