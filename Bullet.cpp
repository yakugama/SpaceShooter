#include "Bullet.h"

Bullet::Bullet(GameObject* p, int tp)
{
	type = tp;

	transform = new MotionComponent();
	transform->position.x = p->getXposition() + 33;
	transform->position.y = p->getYposition();
	transform->velocity.y = -0.3;
	transform->velocity.x = 0;

	sprite = new SpriteComponent();
	if (type == 0)
	{
		sprite->setTexture(TextureManager::bullet, 143, 439, false);
	}
	else
	{
		sprite->setTexture(TextureManager::enemyBullet, 143, 439, false);
	}
	sprite->source.x = sprite->source.y = 0;
	sprite->source.h = sprite->spriteHeight;
	sprite->source.w = sprite->spriteWidth;
	sprite->destination.w = 20;
	sprite->destination.h = 70;
	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;


	
}

Bullet::~Bullet()
{
	if (transform)
	{
		delete transform;
		transform = nullptr;
	}
	
}

void Bullet::update(float deltaTime)
{
	if (type == 0)
	{
		transform->position.x += transform->velocity.x * deltaTime;
		transform->position.y += transform->velocity.y * deltaTime;
	}

	else
	{
		transform->position.x -= transform->velocity.x * deltaTime;
		transform->position.y -= transform->velocity.y * deltaTime;
	}
	
	if (((transform->position.x >= 900) || (transform->position.x <= 0)) || ((transform->position.y > 900) || (transform->position.y < 0)))
	{
		active = false;
	}

	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;
}

void Bullet::render()
{
	TextureManager::Draw(sprite->texture, sprite->source, sprite->destination);
}
