#pragma once
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:
	VisibleGameObject(bool _isTerrain = false);
	virtual ~VisibleGameObject();

	virtual void Load(std::string fileName);
	virtual void Load(std::string fileName, sf::IntRect spriteRect);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(sf::Time elapsedTime);

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;

	virtual float GetWidth() const;
	virtual float GetHeight() const;

	virtual sf::Rect<float> GetBoundingRect() const;
	virtual float GetTopEdge() const;

protected:
	sf::Sprite& GetSprite();
	bool isTerrain;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _fileName;
	bool _isLoaded;
};