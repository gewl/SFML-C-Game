#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject(bool _isTerrain)
	:_isLoaded(false)
{
	isTerrain = _isTerrain;
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

void VisibleGameObject::Update(sf::Time elapsedTime)
{

}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

float VisibleGameObject::GetHeight() const
{
	return _sprite.getGlobalBounds().height;
}

float VisibleGameObject::GetWidth() const
{
	return _sprite.getGlobalBounds().width;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	return _sprite.getGlobalBounds();
}

float VisibleGameObject::GetTopEdge() const
{
	return GetPosition().y + (GetHeight() / 2.0f);
}