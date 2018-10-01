#include "stdafx.h"
#include "PlayerCharacter.h"
#include "GameManager.h"
#include <iostream>

PlayerCharacter::PlayerCharacter() :
	_horizontalVelocity(0),
	_verticalVelocity(0),
	_maxVelocity(600.0f),
	_isGrounded(false),
	_isJumping(false)
{
	sf::IntRect playerSourceSprite(65, 192, 73, 96);
	Load("images/player_spritesheet.png", playerSourceSprite);
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
}

PlayerCharacter::~PlayerCharacter()
{

}

void PlayerCharacter::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerCharacter::GetHorizontalVelocity() const
{
	return _horizontalVelocity;
}

void PlayerCharacter::Update(sf::Time elapsedTime)
{
	bool leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	_isGrounded = GameManager::GetStaticGameObjectManager().CheckCollisions(this->GetBoundingRect(), this->GetPosition());
	if (_isGrounded)
	{
		_verticalVelocity = 0.0f;
	}
	else {
		_verticalVelocity += 6.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || 
		leftKeyPressed && rightKeyPressed)
	{
		_horizontalVelocity = 0.0f;
	}
	else if (leftKeyPressed)
	{
		_horizontalVelocity -= 3.0f;
	}
	else if (rightKeyPressed)
	{
		_horizontalVelocity += 3.0f;
	}
	else {
		if (_horizontalVelocity != 0)
		{
			_horizontalVelocity *= 5 / 6;
			if (_horizontalVelocity >= -0.5f && _horizontalVelocity <= 0.5f)
			{
				_horizontalVelocity = 0.0f;
			}
		}
	}

	if (_horizontalVelocity > _maxVelocity)
	{
		_horizontalVelocity = _maxVelocity;
	}
	else if (_horizontalVelocity < -_maxVelocity)
	{
		_horizontalVelocity = -_maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getGlobalBounds().width / 2 ||
		pos.x > (GameManager::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2))
	{
		_horizontalVelocity = -_horizontalVelocity;
	}

	float frameTime = elapsedTime.asSeconds();
	GetSprite().move(_horizontalVelocity * frameTime, _verticalVelocity * frameTime);	
}
