#include "EnemyWave.h"

EnemyWave::EnemyWave(int n, Enemy::Traiectorie tr, float delta, float disp, float bulTime, Vector2D pos, std::list<GameObject*> &obj, std::list<GameObject*> &bul) : objects(obj), bullets(bul)
{
	total = n;
	traiectorie = tr;
	interval = delta;
	position.x = pos.x;
	position.y = pos.y;
	current = 0;
	dispersion = disp;
	bulletTime = bulTime;
}

void EnemyWave::update(float deltaTime)
{
	static float delay = 0;
	if (current < total)
	{
		if (delay < interval)
		{
			delay += deltaTime;
		}
		else
		{
			delay = 0;
			Enemy *e = new Enemy(dispersion, bulletTime, traiectorie, position, bullets);
			objects.emplace_back(e);
			current++;
		}
	}
}

void EnemyWave::render()
{

}

EnemyWave::~EnemyWave()
{
}
