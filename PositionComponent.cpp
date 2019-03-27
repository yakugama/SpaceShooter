#include "PositionComponent.h"

MotionComponent::MotionComponent()
{
	position.x = position.y = velocity.x = velocity.y = 0;
}

void MotionComponent::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void MotionComponent::setVelocity(int x, int y)
{
	velocity.x = x;
	velocity.y = y;
}
