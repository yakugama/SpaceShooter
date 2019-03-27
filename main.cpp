#include"SDL.h"
#include <SDL_image.h>

#include "Game.h"

int main(int argc, char* argv[])
{
	unsigned int ticks = 0;
	unsigned int prevTicks = 0;
	unsigned int frameTime = 0;

	float deltaTime;

	Game *game = nullptr;

	game = new Game();
	game->init("Galaxy Mirror", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640);

	while (game->isRunning)
	{
		deltaTime = ticks - prevTicks;
		prevTicks = ticks;

		game->handleInput();
		game->update(deltaTime);
		game->render();

		frameTime = (SDL_GetTicks() - ticks);

		if (frameTime < (1000 / 60))
		{
			SDL_Delay(1000 / 60 - frameTime);
		}

		ticks = SDL_GetTicks();
	}

	delete game;

	return 0;
}