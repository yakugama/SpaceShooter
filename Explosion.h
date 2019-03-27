#pragma once

#include "GameObject.h"
#include "TextureManager.h"

class Explosion : public GameObject
{
	int animationIndex;
	float delay;
public:
	Explosion(int xpos, int ypos);
	~Explosion();

	void update(float deltaTime) override;
	void render() override;
};