#pragma once

#include <string_view>

enum EventType
{
	Unknown,
	KeyInput,
	MouseWheelInput,
	MouseMotion
};

struct Event
{
	EventType type = Unknown;
	union {
		std::string_view keyInput;
		struct { int x, y; } mouseWheelInput;
		struct { int xrel, yrel; bool leftMouseButton, rightMouseButton; } mouseMotion;
	} v;
};
