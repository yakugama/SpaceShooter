#include "TextureManager.h"

SDL_Renderer* TextureManager::renderer = nullptr;

SDL_Texture* TextureManager::cosmos = nullptr;
SDL_Texture* TextureManager::player = nullptr;		
SDL_Texture* TextureManager::bullet = nullptr;
SDL_Texture* TextureManager::enemy = nullptr;
SDL_Texture* TextureManager::explosion = nullptr;
SDL_Texture* TextureManager::gameOver = nullptr;
SDL_Texture* TextureManager::enemyBullet = nullptr;

void TextureManager::init(SDL_Renderer *ren)
{
	if (ren)
	{
		renderer = ren;
		cosmos = LoadTexture("sprites/cosmos.png");
		player = LoadTexture("sprites/rocket_animated.png");
		bullet = LoadTexture("sprites/bullet.png")	;
		enemy = LoadTexture("sprites/alien.png");
		explosion = LoadTexture("sprites/shot.png");
		gameOver = LoadTexture("sprites/GameOver.png");
		enemyBullet = LoadTexture("sprites/enemyBullet.png");
	}
}

SDL_Texture * TextureManager::LoadTexture(const char * path)
{
	SDL_Surface* tempSurface = IMG_Load(path);
	if (tempSurface == nullptr)
	{
		std::cout << "Couldn't load texture " << path << std::endl;
	}

	if (renderer)
	{
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		return tex;
	}
	else
	{
		std::cout << "Renderer is not set! Return a nullptr!" << std::endl;
		return nullptr;
	}
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(renderer, tex, &src, &dst);
}

void TextureManager::clean()
{
	if (cosmos)
	{
		SDL_DestroyTexture(cosmos);
		cosmos = nullptr;
	}

	if (player)
	{
		SDL_DestroyTexture(player);
		player = nullptr;
	}

	if (enemy)
	{
		SDL_DestroyTexture(enemy);
		enemy = nullptr;
	}

	if (bullet)
	{
		SDL_DestroyTexture(bullet);
		enemy = nullptr;
	}

	if (enemyBullet)
	{
		SDL_DestroyTexture(enemyBullet);
		enemy = nullptr;
	}

	if (explosion)
	{
		SDL_DestroyTexture(explosion);
		enemy = nullptr;
	}

	if (gameOver)
	{
		SDL_DestroyTexture(gameOver);
		enemy = nullptr;
	}
}
