#pragma once

#include <map>
#include "../misc/sdl_pointers.h"
#include "../misc/singleton.h"
#include "../scene_manager/scene_manager.h"

class App
{
public:
	static constexpr int defaultWidth = 1280;
	static constexpr int defaultHeight = 720;
	static constexpr const char* assetPath = "assets/";

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
	std::map<std::string, std::shared_ptr<Sprite>> sprites;
};
