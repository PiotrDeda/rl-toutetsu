#pragma once

#include <string>

class Logger
{
public:
	static void logInfo(const char *message);
	static void logWarning(const char *message);
	static void logError(const char *message);
};
