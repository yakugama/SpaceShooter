#include "Explosion.h"

Explosion::Explosion(int xpos, int ypos)
{
	transform = new MotionComponent();
	transform->position.x = xpos;
	transform->position.y = ypos-45;
	transform->velocity.x = 0;
	transform->velocity.y = 0;

	sprite = new SpriteComponent();
	sprite->setTexture(TextureManager::explosion, 64, 64, true);
	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;
	sprite->destination.h = 64;
	sprite->destination.w = 64;

	sprite->source.x = sprite->source.y = 0;
	sprite->source.h = sprite->spriteHeight;
	sprite->source.w = sprite->spriteWidth;

	animationIndex = 0;
	type = 3;
	delay = 0.0f;
}

Explosion::~Explosion()
{
	if (transform)
	{
		delete transform;
		transform = nullptr;
	}
}


void Explosion::update(float deltaTime)
{
	if (sprite->animated)
	{
		if (delay < 0.007f)
		{
			delay += deltaTime;
		}
		else
		{
			animationIndex++;
			delay = 0;
		}

		sprite->source.x = sprite->spriteWidth * animationIndex;
	}

	if (animationIndex==11)
	{
		active = false;
	}
}


void Explosion::render()
{
	TextureManager::Draw(sprite->texture, sprite->source, sprite->destination);
}
