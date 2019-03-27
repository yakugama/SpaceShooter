#pragma once
#include "SDL.h"
#include <SDL_image.h>

#include <iostream>

class TextureManager
{
	static SDL_Renderer *renderer;
public:
	static SDL_Texture *cosmos;
	static SDL_Texture *player;
	static SDL_Texture *enemy;
	static SDL_Texture *bullet;
	static SDL_Texture *explosion;
	static SDL_Texture *gameOver;
	static SDL_Texture *enemyBullet;

	static void init(SDL_Renderer *renderer);
	static SDL_Texture* LoadTexture(const char* path);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
	static void clean();
};

