#include "stdafx.h"
#include "GrassSquare.h"

GrassSquare::GrassSquare()
	: VisibleGameObject(true)
{
	Load("images/grass.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
}