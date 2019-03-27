#pragma once

#include "SDL.h"
#include <SDL_image.h>

#include "TextureManager.h"

class Background
{
public:
	Background();
	~Background();

	void Update();
	void Render();

private:
	SDL_Rect dstRectOnScreen, dstRectOffScreen, srcRect;
	SDL_Texture* cosmos;

	int height, width;
	float speed;
	float offset;
};