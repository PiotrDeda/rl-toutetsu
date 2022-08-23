#pragma once

#include <map>
#include "../util/sdl_pointers.h"
#include "../util/singleton.h"
#include "../engine/scene_manager.h"

class App
{
public:
	static constexpr int defaultWidth = 800;
	static constexpr int defaultHeight = 600;
	static constexpr const char* assetPath = "../src/assets/";

	SINGLETON(App)
	~App();

	void init();
	[[nodiscard]] bool isRunning() const;
	void shutdown();
	static const char* getAssetPath(const char* name);
	[[nodiscard]] std::shared_ptr<Sprite> getSprite(const std::string& id) const;

	WindowPtr window;
	RendererPtr renderer;
	SceneManager sceneManager;

private:
	App() = default;

	void loadSprites();

	bool running = true;
	std::map<std::string, Sprite> sprites;
};
