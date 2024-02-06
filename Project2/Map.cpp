#include "Map.h"


//1 -> 20: type: 0 grass, 1 water, 2 bush

//WATER 100-120
//GRASS 21-40
//BUSH 41-60
const int WATER_NUMBER = 100;


int map_1[25][40] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};

int map_2[25][40] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};

int map_3[25][40] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};

Map::Map(int width, int height)
{
	column = width / 32;
	row = height / 32;
	row = 25;
	column = 40;
	
	grass_0 = TextureManager::loadAsset("asset/grass_0.png", GameEngine::renderer);
	grass_0_1 = TextureManager::loadAsset("asset/grass_0_1.png", GameEngine::renderer);
	grass_1 = TextureManager::loadAsset("asset/grass_1.png", GameEngine::renderer);
	grass_2 = TextureManager::loadAsset("asset/grass_2.png", GameEngine::renderer);
	grass_3 = TextureManager::loadAsset("asset/grass_3.png", GameEngine::renderer);
	
	water = TextureManager::loadAsset("asset/water.png", GameEngine::renderer);
	water_TOP = TextureManager::loadAsset("asset/water_TOP.png", GameEngine::renderer);
	water_TOP_LEFT = TextureManager::loadAsset("asset/water_TOP_LEFT.png", GameEngine::renderer);
	water_TOP_RIGHT = TextureManager::loadAsset("asset/water_TOP_RIGHT.png", GameEngine::renderer);
	water_BOTTOM = TextureManager::loadAsset("asset/water_BOTTOM.png", GameEngine::renderer);
	water_BOTTOM_LEFT = TextureManager::loadAsset("asset/water_BOTTOM_LEFT.png", GameEngine::renderer);
	water_BOTTOM_RIGHT = TextureManager::loadAsset("asset/water_BOTTOM_RIGHT.png", GameEngine::renderer);
	water_LEFT = TextureManager::loadAsset("asset/water_LEFT.png", GameEngine::renderer);
	water_RIGHT = TextureManager::loadAsset("asset/water_RIGHT.png", GameEngine::renderer);
	water_TOP_BOTTOM_LEFT = TextureManager::loadAsset("asset/water_TOP_BOTTOM_LEFT.png", GameEngine::renderer);
	water_TOP_BOTTOM_RIGHT = TextureManager::loadAsset("asset/water_TOP_BOTTOM_RIGHT.png", GameEngine::renderer);
	water_TOP_RIGHT_LEFT = TextureManager::loadAsset("asset/water_TOP_RIGHT_LEFT.png", GameEngine::renderer);
	water_BOTTOM_RIGHT_LEFT = TextureManager::loadAsset("asset/water_BOTTOM_RIGHT_LEFT.png", GameEngine::renderer);
	water_TOP_BOTTOM_RIGHT_LEFT = TextureManager::loadAsset	("asset/water_TOP_BOTTOM_RIGHT_LEFT.png", GameEngine::renderer);
	bush = TextureManager::loadAsset("asset/bush_1.png", GameEngine::renderer);
	changeMap();

	
}

Map::~Map()
{
}

bool Map::loadMap(int map[][40])
{
	for (int rowIndex(0); rowIndex < row; rowIndex++) {
		for (int columnIndex(0); columnIndex < column; columnIndex++) {
			Map::map[rowIndex][columnIndex] = map[rowIndex][columnIndex];
		}
	}
	return false;
}

bool Map::drawMap()
{
	SDL_Rect rect, rect2;
	rect.x = 0;
	rect.y = 0;
	rect.w = 32;
	rect.h = 32;

	rect2.x = 0;
	rect2.y = 0;
	rect2.w = 32;
	rect2.h = 32;

	SDL_SetRenderDrawColor(GameEngine::renderer, 255, 0, 0, 255);
	for (int rowIndex(0); rowIndex < row; rowIndex++) {
		for (int columnIndex(0); columnIndex < column; columnIndex++) {
			//std::cout << rowIndex << ":" << columnIndex << "\n";
			switch (map[rowIndex][columnIndex])
			{
			case 20: { //GRASS_0
				TextureManager::draw(grass_0, GameEngine::renderer, &rect2, &rect);
					break;
			}
			case 21: { //GRASS_0
				TextureManager::draw(grass_1, GameEngine::renderer, &rect2, &rect);
				break;
			}
			case 22: { //GRASS_0
				TextureManager::draw(grass_2, GameEngine::renderer, &rect2, &rect);
				break;
			}
			case 23: { //GRASS_0
				TextureManager::draw(grass_3, GameEngine::renderer, &rect2, &rect);
				break;
			}
			case WATER_NUMBER: { //WATER
				// (-1;-1)(-1;0)(-1;1)
				// (0;-1) (0;0) (0;1)
				// (1;-1) (1;0) (1;1)

				//CASE 1: 0 0 0 0
				//	      0 0 1 1
				//            1

				if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] != WATER_NUMBER) {
					TextureManager::draw(water_TOP_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] != WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_BOTTOM_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] != WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_TOP_BOTTOM_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] != WATER_NUMBER) {
					TextureManager::draw(water_TOP, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] != WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] != WATER_NUMBER) {
					TextureManager::draw(water_TOP_RIGHT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] != WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] != WATER_NUMBER) {
					TextureManager::draw(water_TOP_RIGHT_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] != WATER_NUMBER && map[rowIndex + 1][columnIndex] == WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_RIGHT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] != WATER_NUMBER && map[rowIndex + 1][columnIndex] != WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_BOTTOM_RIGHT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] != WATER_NUMBER && map[rowIndex][columnIndex + 1] != WATER_NUMBER && map[rowIndex + 1][columnIndex] != WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_BOTTOM_RIGHT_LEFT, GameEngine::renderer, &rect2, &rect);
				}
				else if (map[rowIndex][columnIndex - 1] == WATER_NUMBER && map[rowIndex][columnIndex + 1] == WATER_NUMBER && map[rowIndex + 1][columnIndex] != WATER_NUMBER && map[rowIndex - 1][columnIndex] == WATER_NUMBER) {
					TextureManager::draw(water_BOTTOM, GameEngine::renderer, &rect2, &rect);
				}
				else TextureManager::draw(water, GameEngine::renderer, &rect2, &rect);

				break;
			}
			
			case 42:
			case 43:
			case 41: { //BUSH				
					TextureManager::draw(bush, GameEngine::renderer, &rect2, &rect);
				break;
			}
			
			default:
				break;
			}
			rect.x = (columnIndex+1) * 32;
		}
		rect.y = (rowIndex+1) * 32;
		rect.x = 0;
	}
	SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
	return false;
}

void Map::changeMap()
{
	switch (Number::random(1,50))
	{
	case 3:
	case 5:
	case 15:
	case 30:
	case 1: {
		loadMap(map_1);
		break;
	}
	case 2: {
		loadMap(map_2);
	}
	default:
		loadMap(map_3);
		break;
	}


	for (int rowIndex(0); rowIndex < row; rowIndex++) {
		for (int columnIndex(0); columnIndex < column; columnIndex++) {

			if (map[rowIndex][columnIndex] == 0) {
				switch (Number::random(1, 100))
				{
				case 1: {
					map[rowIndex][columnIndex] = 21;
					break;
				}
				case 2: {
					map[rowIndex][columnIndex] = 22;
					break;
				}
				case 3: {
					map[rowIndex][columnIndex] = 23;
					break;
				}
				default:
					map[rowIndex][columnIndex] = 20;
					break;
				}
			}
			else if (map[rowIndex][columnIndex] == 1) map[rowIndex][columnIndex] = WATER_NUMBER;
			else if (map[rowIndex][columnIndex] == 2) {
				switch (Number::random(1, 100))
				{
				case 1: {
					map[rowIndex][columnIndex] = 42;
					break;
				}
				case 2: {
					map[rowIndex][columnIndex] = 43;
					break;
				}
				default:
					map[rowIndex][columnIndex] = 41;
					break;
				}
			}
		}
	}
}
