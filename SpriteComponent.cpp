#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
	texture = nullptr;
}

SpriteComponent::~SpriteComponent()
{

}


void SpriteComponent::setTexture(SDL_Texture * tex, int w, int h, bool a)
{
	texture = tex;
	SDL_QueryTexture(texture, NULL, NULL, &totalWidth, NULL);
	spriteWidth = w;
	spriteHeight = h;
	animated = a;
}
