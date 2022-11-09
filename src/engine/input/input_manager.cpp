#include "input_manager.h"

#include <algorithm>

std::string_view InputManager::getInputEvent(SDL_Keycode keycode)
{
	return inputEvents.contains(keycode) ? inputEvents[keycode] : "NULL";
}

void InputManager::assignInputEvent(SDL_Keycode keycode, std::string_view inputEvent)
{
	auto it = std::find_if(inputEvents.begin(), inputEvents.end(), [inputEvent](const auto& pair) { return pair.second == inputEvent; });
	if (it != inputEvents.end())
		inputEvents.erase(it);
	inputEvents[keycode] = inputEvent;
}

void InputManager::removeInputEvent(std::string_view inputEvent)
{
	auto it = std::find_if(inputEvents.begin(), inputEvents.end(), [inputEvent](const auto& pair) { return pair.second == inputEvent; });
	if (it != inputEvents.end())
		inputEvents.erase(it);
}
