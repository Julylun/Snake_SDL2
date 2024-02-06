#include "Snake.h"

Snake::Snake()
{
	for (int i(0); i < 1000; i++) {
		tail[0][i] = -1;
		tail[1][i] = -1;
	}
	head[0][0] = 3;
	head[0][1] = 3;

	dstRect.h = 32;
	dstRect.w = 32;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	destination = 2;
	tailCount = 2;
	headTexture = TextureManager::loadAsset("asset/snakeHead.png", GameEngine::renderer);
	tailTexture = TextureManager::loadAsset("asset/snakeTail.png", GameEngine::renderer);
	delayMove = 0;

	isAlive = true;
}

Snake::~Snake()
{
}

void Snake::update()
{
	delayMove++;
	if (delayMove > 3) {
		for (int i(tailCount-1); i > 0; i--) {
			tail[0][i] = tail[0][i - 1];
			tail[1][i] = tail[1][i - 1];
			if (head[0][0] == tail[0][i] && head[0][1] == tail[1][i]) {
				isAlive = false;
			}
		}
		tail[0][0] = head[0][0];
		tail[1][0] = head[0][1];

		switch (destination)
		{
		case 0: {
			head[0][0] -= 1;
			break;
		}
		case 1: {
			head[0][1] -= 1;
			break;
		}
		case 2: {
			head[0][0] += 1;
			break;
		}
		case 3: {
			head[0][1] += 1;
			break;
		}
		default:
			break;
		}
		
		if (head[0][0] > 39) {
			head[0][0] = 0;
			isNextMap = true;
		}
		if (head[0][0] < 0) {
			head[0][0] = 39;
			isNextMap = true;
		}
		if (head[0][1] > 24) {
			head[0][1] = 0;
			isNextMap = true;
		}
		if (head[0][1] < 0) {
			head[0][1] = 24;
			isNextMap = true;
		}
		

		delayMove = 0;
	}
	
}

void Snake::render()
{
	for (int i(0); i < tailCount; i++) {
		dstRect.x = tail[0][i] * 32;
		dstRect.y = tail[1][i] * 32;
		//std::cout << "(" << dstRect.x << ";" << dstRect.y << ") | ";
		TextureManager::draw(tailTexture, GameEngine::renderer, &srcRect, &dstRect);
	}

	dstRect.x = head[0][0] * 32;
	dstRect.y = head[0][1] * 32;
	TextureManager::draw(headTexture, GameEngine::renderer, &srcRect, &dstRect);
	//std::cout << "\n";
	//system("pause");
	
}

void Snake::setDestination(int setNumber)
{
	destination = setNumber;
}

void Snake::feed()
{
	tailCount++;
}

void Snake::damaged()
{
	tailCount--;
}

int Snake::getTailCount()
{
	return tailCount;
}

bool Snake::alive()
{
	return isAlive;
}

bool Snake::nextMap()
{
	return isNextMap;
}

void Snake::setNextMap(bool isTrue) {
	isNextMap = isTrue;
}

void Snake::resetTail() {
	for (int i(0); i < tailCount; i++) {
		tail[0][i] = -1;
		tail[1][i] = -1;
	}
}

