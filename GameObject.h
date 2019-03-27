#pragma once

#include "SDL.h"

#include "Components.h"
#include "Entity.h"

class GameObject 
{
protected:
	SpriteComponent* sprite;
	MotionComponent *transform;

public:
	bool active = true;
	int type;

	int getXposition() { return static_cast<int>(transform->position.x); }
	int getYposition() { return static_cast<int>(transform->position.y); }
	int getSpriteWidth() { return sprite->spriteWidth; }
	int getSpriteHeight() { return sprite->spriteHeight; }

	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;

	static bool collides(GameObject* obj1, GameObject* obj2);

	virtual ~GameObject() {};
};
