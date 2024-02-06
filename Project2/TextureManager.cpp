#include "TextureManager.h"

SDL_Texture* TextureManager::loadAsset(const char* filePath, SDL_Renderer* renderer) {
	SDL_Surface* tempSurface = IMG_Load(filePath);
	SDL_Texture* returningTexture;
	if (tempSurface == NULL) {
		std::cout << "[TextureManager](loadAsset): Load asset file path at " << filePath << " is failure\n";
		system("pause");
	}

	 returningTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (returningTexture == NULL) {
		std::cout << "[TextureManager](loadAsset): Creating texture from surface is failure - " << SDL_GetError() << "\n";
		system("pause");
	}
	std::cout << returningTexture << "\n";
	
	SDL_FreeSurface(tempSurface);
	return returningTexture;
}

bool TextureManager::draw(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect* sourceRect, SDL_Rect* destinationRect)
{
	if (SDL_RenderCopy(renderer, texture, sourceRect, destinationRect) != 0) {
		std::cout << "[TextureManager](draw): SDL_RenderCopy occurs errors - " << SDL_GetError() << "\n";
		std::cout << "Error occurs at: " << destinationRect->x/32 << ":" << destinationRect->y/32 << "\n";
		system("pause");
		return false;
	}
	return true;
}
