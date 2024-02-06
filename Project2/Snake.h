#ifndef SNAKE_H
#define SNAKE_H

#include "GameEngine.h"

class Snake {
public:
	Snake();
	~Snake();

	
	void update();
	void render();
	void setDestination(int setNumber);
	int head[1][2];
	void feed();
	void damaged();
	int getTailCount();
	bool alive();
	bool nextMap();
	void setNextMap(bool isTrue); 
	void resetTail();

private:
	SDL_Rect srcRect, dstRect;
	SDL_Texture* headTexture;
	SDL_Texture* tailTexture;
	int tail[2][1000]; //0 x ; 1 y
	
	int tailCount;
	int destination; // 0 A ; 1 W ; 2 D ; 3 S
	int delayMove;
	bool isAlive;
	bool isNextMap;
};

#endif