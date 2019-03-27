#pragma once

#include <cstdlib>
#include <time.h> 
#include <list>

#include "GameObject.h"
#include "Bullet.h"

#include "TextureManager.h"

class Enemy : public GameObject
{
public:
	enum Traiectorie { SIN, ZIGZAG };
private:
	Traiectorie traiectorie;
	float dispersion;
	float directionVariationSpeed;
	float bulletTime;
	std::list<GameObject*> &bullets;
	float bulletDelay;

public:
	Enemy(float disp, float bulTime, Traiectorie tr,  Vector2D pos, std::list<GameObject*> &bul);
	~Enemy();

	void update(float deltaTime) override;
	void render() override;

};