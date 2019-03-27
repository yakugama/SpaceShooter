#include "Background.h"

Background::Background()
{
	if (TextureManager::cosmos)
	{
		this->cosmos = TextureManager::cosmos;
		//aflarea inaltimii si latimii
		SDL_QueryTexture(cosmos, NULL, NULL, &width, &height);

		//Setare coordonate dreptunghi-sursa
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.h = height;
		srcRect.w = width;

		//Setare coordonate pt dreptunghiul din ecran
		dstRectOnScreen.x = 0;
		dstRectOnScreen.y = 0;
		dstRectOnScreen.h = height;
		dstRectOnScreen.w = width;

		//Setare coordonate pt dreptunghiul inafara ecranului
		dstRectOffScreen.x = 0;
		dstRectOffScreen.y = -height;
		dstRectOffScreen.h = height;
		dstRectOffScreen.w = width;

		speed = 0.3f;
		offset = 0.0f;
	}
}

Background::~Background()
{
	if (cosmos)
	{
		SDL_DestroyTexture(cosmos);
		cosmos = nullptr;
	}
}

void Background::Update()
{
	if (dstRectOffScreen.y == 0)
	{
		dstRectOnScreen.y = 0;
		dstRectOffScreen.y = -height;
		offset = 0.0f;
	}
	else
	{
		offset += speed;
		//dstRectOffScreen.y = (int)(dstRectOffScreen.y + Yposition);
		dstRectOnScreen.y = (int)(offset);
		dstRectOffScreen.y = dstRectOnScreen.y - height;
	}
}

void Background::Render()
{
	TextureManager::Draw(cosmos, srcRect, dstRectOffScreen);
	TextureManager::Draw(cosmos, srcRect, dstRectOnScreen);
}

