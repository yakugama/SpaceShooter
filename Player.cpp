#include "Player.h"
#include "Components.h"

Player::Player()
{
	transform = new MotionComponent();
	transform->position.x = transform->position.y = 400;
	transform->velocity.x = transform->velocity.y = 0;

	sprite = new SpriteComponent();
	sprite->setTexture(TextureManager::player, 169, 378, true);
	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;
	sprite->destination.h = sprite->spriteHeight / 2;
	sprite->destination.w = sprite->spriteWidth / 2;

	sprite->source.x = sprite->source.y = 0;
	sprite->source.h = sprite->spriteHeight;
	sprite->source.w = sprite->spriteWidth;

	type = 1;
}

Player::~Player()
{
	if (transform)
	{
		delete transform;
		transform = nullptr;
	}
}


void Player::update(float deltaTime)
{
	transform->position.x += transform->velocity.x * deltaTime;
	transform->position.y += transform->velocity.y * deltaTime;

	sprite->destination.x = (int)transform->position.x;
	sprite->destination.y = (int)transform->position.y;

	if (sprite->animated)
	{
		sprite->source.x = sprite->spriteWidth * static_cast<int>((SDL_GetTicks() / 200) % (sprite->totalWidth / sprite->spriteWidth));
	}
}

void Player::render()
{
	TextureManager::Draw(sprite->texture, sprite->source, sprite->destination);
}

void Player::handleInput(SDL_Event * event)
{
	static const float speed = 0.3;
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_w:
			transform->velocity.y = -speed;
			break;
		case SDLK_DOWN:
		case SDLK_s:
			transform->velocity.y = speed;
			break;
		case SDLK_LEFT:
		case SDLK_a:
			transform->velocity.x = -speed;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			transform->velocity.x = speed;
			break;
		default:
			break;
		}
	}

	if (event->type == SDL_KEYUP)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
			transform->velocity.y = 0;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			transform->velocity.y = 0;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			transform->velocity.x = 0;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			transform->velocity.x = 0;
			break;
		default:
			break;
		}
	}
}

