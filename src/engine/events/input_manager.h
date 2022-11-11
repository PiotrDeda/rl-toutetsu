#pragma once

#include <SDL_keycode.h>
#include <map>
#include <optional>
#include <string_view>
#include "event.h"

class InputManager
{
public:
	std::optional<Event> getInputEvent(SDL_Keycode keycode);
	void assignInputEventValue(SDL_Keycode keycode, std::string_view inputEvent);
	void removeInputEventValue(std::string_view inputEvent);

private:
	std::map<SDL_Keycode, std::string_view> inputEvents;
};
