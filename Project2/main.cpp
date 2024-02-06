

#include "GameEngine.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;
#define _WIN32_WINNT as 0x0500

int main(int argc, char* argv[]) {
	

	GameEngine* gameEngine = new GameEngine();
	gameEngine->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (gameEngine->running()) {
		Uint32 startFrameTime = SDL_GetTicks();
		
		gameEngine->eventHandle();
		gameEngine->update();
		gameEngine->render();

		Uint32 lastFrameTime = SDL_GetTicks();

		//std::cout << "Current Performance Frequency: " << SDL_GetPerformanceFrequency() << "\n";
		//std::cout << "Current Performance Counter: " << SDL_GetPerformanceCounter() << "\n";

		if (lastFrameTime - startFrameTime < DELAY_TIME) {
			//std::cout << DELAY_TIME - (lastFrameTime - startFrameTime) << "\n";
			SDL_Delay(DELAY_TIME - (lastFrameTime - startFrameTime));
		}
		//SDL_Delay(500);
	}
	std::cout << "\nGAME OVER\n";
	system("pause");
	return 0;
}