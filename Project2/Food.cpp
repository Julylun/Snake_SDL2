#include "Food.h"

Food::Food(int width, int height)
{
	setRandomPosition(width, height);
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	dstRect.w = 32;
	dstRect.h = 32;
}

Food::~Food()
{
}

void Food::setRandomPosition(int width, int height)
{
	xPos = Number::random(0, width);
	yPos = Number::random(0, height);

	switch (Number::random(1, 20))
	{
	case 1:
	case 5: {
		isHarmful = true;
		skin = TextureManager::loadAsset("asset/harmful_food.png", GameEngine::renderer);
		break;
	}
	default:
		skin = TextureManager::loadAsset("asset/food.png", GameEngine::renderer);
		isHarmful = false;
		break;
	}

	
}

void Food::render()
{
	dstRect.x = 32 * xPos;
	dstRect.y = 32 * yPos;
	TextureManager::draw(skin, GameEngine::renderer, &srcRect, &dstRect);
}
