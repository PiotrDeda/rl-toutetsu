#pragma once

#include <string_view>

enum EventType
{
	Unknown,
	KeyInput,
	MouseWheelInput,
	MouseMotion
};

union Event
{
	EventType type = Unknown;
	struct { EventType type; std::string_view v; } keyInput;
	struct { EventType type; int x, y; } mouseWheelInput;
	struct { EventType type; int xrel, yrel; bool leftMouseButton, rightMouseButton; } mouseMotion;
};
