#pragma once

#include "../util/sdl_pointers.h"
#include "../util/singleton.h"
#include "../engine/scene_manager.h"

class App
{
public:
	static constexpr int defaultWidth = 800;
	static constexpr int defaultHeight = 600;

	SINGLETON(App)
	~App();

	void init();
	[[nodiscard]] const WindowPtr& getWindow() const;
	[[nodiscard]] const SurfacePtr& getWindowSurface() const;
	[[nodiscard]] bool isRunning() const;
	void shutdown();

	SceneManager sceneManager;

private:
	App() = default;
	WindowPtr window;
	SurfacePtr windowSurface;
	bool running = true;
};
