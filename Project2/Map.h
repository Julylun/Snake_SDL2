#ifndef MAP_H
#define MAP_H
#include "GameEngine.h"

class Map {
public:
	Map(int width, int height);
	~Map();

	bool loadMap(int map[][40]);
	bool drawMap();
	void changeMap();
private:
	int column, row;
	int map[1000][1000];
	SDL_Texture* grass_0;
	SDL_Texture* grass_0_1;
	SDL_Texture* grass_1;
	SDL_Texture* grass_2;
	SDL_Texture* grass_3;
	SDL_Texture* sand;

	SDL_Texture* water;
	SDL_Texture* water_TOP;
	SDL_Texture* water_TOP_LEFT;
	SDL_Texture* water_TOP_RIGHT;
	SDL_Texture* water_BOTTOM;
	SDL_Texture* water_BOTTOM_LEFT;
	SDL_Texture* water_BOTTOM_RIGHT;
	SDL_Texture* water_LEFT;
	SDL_Texture* water_RIGHT;
	SDL_Texture* water_TOP_BOTTOM_LEFT;
	SDL_Texture* water_TOP_BOTTOM_RIGHT;
	SDL_Texture* water_TOP_RIGHT_LEFT;
	SDL_Texture* water_BOTTOM_RIGHT_LEFT;
	SDL_Texture* water_TOP_BOTTOM_RIGHT_LEFT;


	SDL_Texture* bush;

};

#endif