#pragma once
#include "Vector2D.h"

class MotionComponent
{
public:
	Vector2D position;
	Vector2D velocity;

	MotionComponent();
	void setPosition(int x, int y);
	void setVelocity(int x, int y);
};