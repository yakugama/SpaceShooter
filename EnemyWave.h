#pragma once

#include "Entity.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Enemy.h"

#include <iostream>
#include <list>

class EnemyWave 
{

private:
	Enemy::Traiectorie traiectorie;
	int total;
	float interval;
	Vector2D position;
	float dispersion;
	float bulletTime;

	std::list<GameObject*> &objects;
	std::list<GameObject*> &bullets;

	int current;
public:
	EnemyWave(int n, Enemy::Traiectorie tr, float delta, float disp, float bulTime, Vector2D pos, std::list<GameObject*> &obj, std::list<GameObject*> &bul);

	void update(float deltaTime);
	void render();

	~EnemyWave();
};