#include "GameEngine.h"

SDL_Renderer* GameEngine::renderer = nullptr;
Map* map;
Snake* snake;
std::vector<Food> vFood;
GameEngine::GameEngine()
{
	std::cout << "[GameEngine](init): GameEngine is created\n";
}



GameEngine::~GameEngine()
{
}

bool GameEngine::init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen) {
	//INIT
	std::cout << "[GameEngine](init): Initializing...\n";
	int flag = 0;
	keyPressed = 2;

	


	screenHeight = width;
	screenHeight = height;

	if (isFullScreen) flag = 1;
	std::cout << "[GameEngine](init): flag = " << flag << "\n";
	
	std::cout << "[GameEngine](init): Creating window...\n";
	window = SDL_CreateWindow(title, xPos, yPos, width, height, flag);
	if (window == NULL) {
		std::cout << "[GameEngine](init): Creating window processing is failure - " << SDL_GetError() << "\n";
		system("pause");
		goto falseCase;
	}
	std::cout << "[GameEngine](init): Window is created\n";

	std::cout << "[GameEngine](init): Creating renderer...\n";
	GameEngine::renderer = SDL_CreateRenderer(window, -1, 0);
	if (window == NULL) {
		std::cout << "[GameEngine](init): Creating renderer processing is failure - " << SDL_GetError() << "\n";
		system("pause");
		goto falseCase;
	}
	std::cout << "[GameEngine](init): Renderer is created\n";
	
	snake = new Snake();
	map = new Map(30, 30);
	for (int i(0); i <= 10; i++) {
		Food* food;
		food = new Food(40, 25);
		vFood.push_back(*food);
	}
	







	std::cout << "[GameEngine](init): Initialization is completed!\n";
	isRunning = true;
	return true;
falseCase:
	isRunning = false;
	return false;
}



void GameEngine::eventHandle()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (SDL_KEYDOWN == event.type) {
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
		{
			//std::cout << "[GameEngine](eventHandle): A button was pressed\n";
			if (keyPressed != 2)
			keyPressed = 0;
			break;
		}
		case SDLK_d:
		{
			//std::cout << "[GameEngine](eventHandle): D button was pressed\n";
			if (keyPressed != 0)
			keyPressed = 2;
			break;
		}
		case SDLK_w:
		{
			//std::cout << "[GameEngine](eventHandle): W button was pressed\n";
			if (keyPressed != 3)
			keyPressed = 1;
			break;
		}
		case SDLK_s:
		{
			//std::cout << "[GameEngine](eventHandle): S button was pressed\n";
			if (keyPressed != 1)
			keyPressed = 3;
			break;
		}
		default:
			break;
		}
	}
	
	snake->setDestination(keyPressed);

	if (event.type == SDL_QUIT) {
		SDL_Quit();
		std::cout << "[GameEngine](eventHandle): Quit button was clicked\n";
		exit(0);
	}
	
}

void GameEngine::update()
{
	for (Food &food : vFood) {
		if (snake->head[0][0] == food.xPos && snake->head[0][1] == food.yPos) {
			if (food.isHarmful) snake->damaged();
			else snake->feed();
			food.setRandomPosition(40, 25);
		}
	}
	snake->update();
	if (!snake->alive()) GameEngine::isRunning = false;
	if (snake->nextMap()) {
		map->changeMap();
		snake->setNextMap(false);
		for (Food& food : vFood) {
			food.setRandomPosition(40, 25);
		}
		snake->resetTail();
	}
}

void GameEngine::render()
{
	SDL_RenderClear(renderer);
	//std::cout << "RENDER\n";
	
	map->drawMap();
	for (Food food : vFood) {
		food.render();
	}
	snake->render();
	SDL_RenderPresent(renderer);

	//system("cls");
	//std::cout << snake->getTailCount() << "\n";
	//std::cout << snake->head[0][0] << ":" << snake->head[0][1] << "\n";
}

bool GameEngine::running()
{
	return isRunning;
}


