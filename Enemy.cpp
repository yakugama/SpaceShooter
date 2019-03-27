#include "Enemy.h"

Enemy::Enemy(float disp, float bulTime, Traiectorie tr, Vector2D pos, std::list<GameObject*> &bul) : bullets(bul)
{
	dispersion = disp;
	type = 2;
	directionVariationSpeed = 0;
	traiectorie = tr;
	bulletTime = bulTime;
	bulletDelay = 0.0f;

	transform = new MotionComponent();
	transform->position.x = pos.x;
	transform->position.y = pos.y;

	sprite = new SpriteComponent();
	sprite->setTexture(TextureManager::enemy, 400, 203, false);
	sprite->source.x = sprite->source.y = 0;
	sprite->source.h = sprite->spriteHeight;
	sprite->source.w = sprite->spriteWidth;
	sprite->destination.w = 80;
	sprite->destination.h = 40;
	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;

	switch (tr) {
	case ZIGZAG:
		transform->velocity.x = 0.2f;
		transform->velocity.y = 0.03f;
		break;
	case SIN:
		transform->velocity.x = 0;
		transform->velocity.y = 0.04f;
		break;
	}

}

Enemy::~Enemy()
{
	if (transform)
	{
		delete transform;
		transform = nullptr;
	}
}


void Enemy::update(float deltaTime)
{
	if (bulletDelay < bulletTime)
	{
		bulletDelay += deltaTime;
	}
	else
	{
		Bullet *b = new Bullet(this, 1);
		bullets.push_back(b);
		bulletDelay = 0;
	}

	switch (traiectorie)
	{
	case SIN:
		directionVariationSpeed += 3.0f * deltaTime / dispersion;
		transform->velocity.x = sinf(directionVariationSpeed) * 0.25f;

		break;
	case ZIGZAG:
		if (transform->position.x > 650) {
			transform->velocity.x = -0.2f;
		}
		else if (transform->position.x < 150) {
			transform->velocity.x = 0.2f;
		}
	}

	transform->position.x += transform->velocity.x * deltaTime;
	transform->position.y += transform->velocity.y * deltaTime;


	if (transform->position.y > 640)
	{
		active = false;
	}

	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;
}

void Enemy::render()
{
	TextureManager::Draw(sprite->texture, sprite->source, sprite->destination);
}
