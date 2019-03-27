#pragma once

#include "GameObject.h"

bool GameObject::collides(GameObject* obj1, GameObject* obj2)
{
	if (SDL_HasIntersection(&obj1->sprite->destination, &obj2->sprite->destination) == SDL_TRUE)
	{
			return true;
	}
	else
	{
		return false;
	}
}