#pragma once

#include <map>
#include "../events/input_manager.h"
#include "../misc/sdl_pointers.h"
#include "../misc/singleton.h"
#include "../scene_manager/scene_manager.h"

class App
{
public:
	SINGLETON(App)
	~App();

	void init();
	void loadSprites(std::map<std::string, std::shared_ptr<Sprite>> loadedSprites);
	int run();
	void shutdown();
	static const char* getAssetPath(const char* name, const char* fileType = "png");
	[[nodiscard]] std::shared_ptr<Sprite> getSprite(const std::string& id) const;
	[[nodiscard]] int getMouseX() const;
	[[nodiscard]] int getMouseY() const;

	WindowPtr window;
	RendererPtr renderer;
	FontPtr font;
	SceneManager sceneManager;
	InputManager inputManager;

private:
	static constexpr int defaultWidth = 1280;
	static constexpr int defaultHeight = 720;
	static constexpr const char* assetPath = "assets/";

	App() = default;

	void updateWindowSize();

	bool running = true;
	float widthMultiplier = 1;
	float heightMultiplier = 1;
	int widthOffset = 0;
	int heightOffset = 0;
	std::map<std::string, std::shared_ptr<Sprite>> sprites;
};
