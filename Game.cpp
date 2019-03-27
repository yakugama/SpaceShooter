#include <iostream>
#include <fstream>

#include "Game.h"
#include "Background.h"


Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	background = nullptr;
	isRunning = false;
}


void Game::init(const char * title, int xpos, int ypos, int width, int height)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
	

		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		if (window)
		{
			//std::cout << "Windows created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			//std::cout << "Renderer created!" << std::endl;
		}

		TextureManager::init(renderer);

		background = new Background();

		player = new Player();

		waves.push_back(new EnemyWave(10, Enemy::SIN, 900.0f, 2000.0f, 2100.0f, Vector2D(200, -50), enemies, bullets));

		score = 0;

		isRunning = true;
	}
}

void Game::update(float deltaTime)
{
	background->Update();


	if (player->active)
	{
		generateWave(deltaTime);

		player->update(deltaTime);

		updateObjects(deltaTime);

		CollisionCheck();

		if (player->active)
		{
			DeleteInactive();
		}
		else
		{
			clean();
		}

	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	background->Render();
	if (player->active)
	{
		renderObjects();
	}
	else
	{
		TextureManager::Draw(TextureManager::gameOver, SDL_Rect{ 0,0, 800, 640 }, SDL_Rect{ 0,0,800, 640 });
	}

	SDL_RenderPresent(renderer);
}

void Game::handleInput()
{
	static bool buttonPressed = false;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN: 
			player->handleInput(&event);
			break;
		case SDL_KEYUP:
			player->handleInput(&event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if ((event.button.button == SDL_BUTTON_LEFT) && !buttonPressed)
			{
				Bullet *b = new Bullet(player, 0);
				bullets.push_back(b);
				buttonPressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			buttonPressed = false;
		default:
			break;
	}
}

void Game::generateWave(float deltaTime)
{
	static float delay = 0.0f;
	if (delay < 20000)
	{
		delay += deltaTime;
	}
	else
	{
		if (SDL_GetTicks() % 2 == 0)
		{
			waves.push_back(new EnemyWave(10, Enemy::SIN, 900.0f, 2000.0f, 3000.0f, Vector2D(200, -50), enemies, bullets));
			
		}
		else
		{
			waves.push_back(new EnemyWave(10, Enemy::ZIGZAG, 900.0f, 30.0f, 2500.0f, Vector2D(400, -50), enemies, bullets));
			waves.push_back(new EnemyWave(10, Enemy::ZIGZAG, 900.0f, 30.0f, 2500.0f, Vector2D(700, -50), enemies, bullets));
		}
		delay = 0.0f;
	}
}

void Game::CollisionCheck()
{

	for (auto i : bullets)
	{
		if ((i->active == true) && (i->type == 0))
		{
			for (auto j : enemies)
			{
				if (j->active == true)
				{
					if (GameObject::collides(i, j) == true)
					{
						score++;
						i->active = false;
						j->active = false;
						Explosion *e = new Explosion(i->getXposition(), i->getYposition());
						explosions.push_back(e);
					}
				}
			}
		}
	}

	for (auto i : bullets)
	{
		if (i->active == true)
		{
			if (GameObject::collides(i, player) == true)
			{
				if (i->type == 1)
				{
					player->active = false;
				}
			}
		}
	}

	for (auto i : enemies)
	{
		if ((i->active == true) && (player->active == true))
		{
			if (GameObject::collides(i, player) == true)
			{
				player->active = false;
			}
		}
	}
}

void Game::DeleteInactive()
{
	enemies.remove_if([](GameObject* obj)
	{
		if (obj->active == false)
		{
			delete obj;
			return true;
		}
		else return false;
	});


	bullets.remove_if([](GameObject* obj)
	{
		if (obj->active == false)
		{
			delete obj;
			return true;
		}
		else return false;
	});


	explosions.remove_if([](GameObject* obj)
	{
		if (obj->active == false)
		{
			delete obj;
			return true;
		}
		else return false;
	});
}

void Game::updateObjects(float deltaTime)
{
	for (auto wave : waves)
	{
		wave->update(deltaTime);
	}

	for (auto i : enemies)
	{
		i->update(deltaTime);
	}

	for (auto i : bullets)
	{
		i->update(deltaTime);
	}

	for (auto i : explosions)
	{
		i->update(deltaTime);
	}
}

void Game::renderObjects()
{
	player->render();
	for (auto i : enemies)
	{
		i->render();
	}

	for (auto i : bullets)
	{
		i->render();
	}

	for (auto i : explosions)
	{
		i->render();
	}
}

void Game::clean()
{

	for (auto i : waves) 
	{
		delete i;
	}

	for (auto i : enemies)
	{
		delete i;
	}

	for (auto i : bullets)
	{
		delete i;
	}

	for (auto i : explosions)
	{
		delete i;
	}

}


Game::~Game()
{
	if (window)
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	if (renderer)
	{
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	if (player->active)
	{
		clean();
	}

	std::cout << "Score: " << score << std::endl;

	TextureManager::clean();
}