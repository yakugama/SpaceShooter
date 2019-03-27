#pragma once

#include"SDL.h"
#include <SDL_image.h>

#include <iostream>
#include <list>
#include <vector>

#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyWave.h"	
#include "Explosion.h"

#include "Background.h"
#include "TextureManager.h"


class Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	Background* background;

	std::list<GameObject*> enemies;
	std::list<GameObject*> bullets;
	std::list<GameObject*> explosions;

	std::vector<EnemyWave*> waves;

	Player *player;

	int score;
public:
	bool isRunning;
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);

	void update(float deltaTime);
	void render();

	void handleInput();

	void generateWave(float deltaTime);

	void CollisionCheck();
	
	void DeleteInactive();

	void updateObjects(float deltaTime);
	void renderObjects();

	void clean();
};