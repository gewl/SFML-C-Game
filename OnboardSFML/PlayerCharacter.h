#pragma once
#include "VisibleGameObject.h"

class PlayerCharacter :
	public VisibleGameObject
{
public:
	PlayerCharacter();
	~PlayerCharacter();

	void Update(sf::Time elapsedTime);
	void Draw(sf::RenderWindow& rw);
	
	float GetVelocity() const;

private:
	float _velocity;
	float _maxVelocity;

	int groundedCount;
};