#pragma once

#include "GameObject.h"

#include "TextureManager.h"

class Bullet : public GameObject
{
public:
	Bullet(GameObject *p, int tp);
	~Bullet();

	void update(float deltaTime);
	void render();
};