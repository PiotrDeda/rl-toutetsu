#pragma once

#define SINGLETON(T) \
static T& get() \
{ \
	static T instance; \
	return instance; \
} \
T(const T&) = delete; \
T& operator=(const T&) = delete; \
T(T&&) = delete; \
T& operator=(T&&) = delete;
