#ifndef  TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include "GameEngine.h"

class TextureManager {
public:
	static SDL_Texture* loadAsset(const char* filePath, SDL_Renderer* renderer);
	static bool draw(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect* sourceRect, SDL_Rect* destinationRect);
};

#endif // ! TEXTURE_MANAGER_H

