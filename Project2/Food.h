#ifndef FOOD_H
#define FOOD_H
#include "GameEngine.h"

class Food {
public:
	Food(int width, int height);
	~Food();
	int xPos, yPos;
	void setRandomPosition(int width, int height);
	void render();
	bool isHarmful;	
private:
	SDL_Rect srcRect, dstRect;
	SDL_Texture* skin;
	
};

#endif