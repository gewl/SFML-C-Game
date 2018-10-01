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
	
	float GetHorizontalVelocity() const;

private:
	float _horizontalVelocity;
	float _verticalVelocity;
	float _maxVelocity;

	bool _isGrounded;
	bool _isJumping;
};