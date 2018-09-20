#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
	:_isLoaded(false)
{
}

VisibleGameObject::~VisibleGameObject() { }

void VisibleGameObject::Load(std::string fileName)
{
	if (_texture.loadFromFile(fileName) == false)
	{
		_fileName = "";
		_isLoaded = false;
	}
	else {
		_fileName = fileName;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void VisibleGameObject::Load(std::string fileName, sf::IntRect spriteRect)
{
	if (_texture.loadFromFile(fileName) == false)
	{
		_fileName = "";
		_isLoaded = false;
	}
	else {
		_fileName = fileName;
		sf::Texture texture;

		_sprite.setTexture(_texture);
		_sprite.setTextureRect(spriteRect);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}