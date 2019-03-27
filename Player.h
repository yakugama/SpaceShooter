#pragma once

#include "GameObject.h"
#include "TextureManager.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void render();

	void handleInput(SDL_Event *event);
};