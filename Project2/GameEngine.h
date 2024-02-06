#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "Header.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Map.h"
#include "TextureManager.h"
#include "Snake.h"
#include "Number.h"
#include "Food.h"
#include "Position.h"


class GameEngine {
public:
	GameEngine();
	~GameEngine();

	bool init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen);
	void eventHandle();
	void update();
	void render();
	static SDL_Renderer* renderer;
	bool running();
	void defaultGameSetup();

private:
	SDL_Window* window;
	int keyPressed;
	bool isRunning;
	int screenWidth, screenHeight;
};

#endif