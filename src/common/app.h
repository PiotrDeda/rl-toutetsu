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
	[[nodiscard]] bool isRunning() const;
	void shutdown();

	WindowPtr window;
	RendererPtr renderer;
	SceneManager sceneManager;

private:
	App() = default;
	bool running = true;
};
