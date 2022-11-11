#include "input_manager.h"

#include <algorithm>

std::optional<Event> InputManager::getInputEvent(SDL_Keycode keycode)
{
	return inputEvents.contains(keycode) ? std::optional<Event>({.keyInput = {KeyInput, inputEvents[keycode]}}) : std::nullopt;
}

void InputManager::assignInputEventValue(SDL_Keycode keycode, std::string_view inputEvent)
{
	auto it = std::find_if(inputEvents.begin(), inputEvents.end(),
						   [inputEvent](const auto& pair) { return pair.second == inputEvent; });
	if (it != inputEvents.end())
		inputEvents.erase(it);
	inputEvents[keycode] = inputEvent;
}

void InputManager::removeInputEventValue(std::string_view inputEvent)
{
	auto it = std::find_if(inputEvents.begin(), inputEvents.end(),
						   [inputEvent](const auto& pair) { return pair.second == inputEvent; });
	if (it != inputEvents.end())
		inputEvents.erase(it);
}
