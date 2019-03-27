#pragma once
#include "SDL.h"
#include <SDL_image.h>

class SpriteComponent
{
public:
	SDL_Texture *texture;
	SDL_Rect source, destination;

	int spriteWidth, totalWidth;
	int spriteHeight;

	bool animated;

	SpriteComponent();
	~SpriteComponent();

	void setTexture(SDL_Texture* tex, int w, int h, bool a);
};