#include "stdafx.h"
#include "PlayerCharacter.h"
#include "GameManager.h"

PlayerCharacter::PlayerCharacter() :
	_velocity(0),
	_maxVelocity(600.0f)
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

float PlayerCharacter::GetVelocity() const
{
	return _velocity;
}

void PlayerCharacter::Update(sf::Time elapsedTime)
{
	bool leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || 
		leftKeyPressed && rightKeyPressed)
	{
		_velocity = 0.0f;
	}
	else if (leftKeyPressed)
	{
		_velocity -= 3.0f;
	}
	else if (rightKeyPressed)
	{
		_velocity += 3.0f;
	}
	else {
		if (_velocity != 0)
		{
			_velocity *= 5 / 6;
			if (_velocity >= -0.5f && _velocity <= 0.5f)
			{
				_velocity = 0.0f;
			}
		}
	}

	if (_velocity > _maxVelocity)
	{
		_velocity = _maxVelocity;
	}
	else if (_velocity < -_maxVelocity)
	{
		_velocity = -_maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getGlobalBounds().width / 2 ||
		pos.x > (GameManager::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2))
	{
		_velocity = -_velocity;
	}

	float frameTime = elapsedTime.asSeconds();
	GetSprite().move(_velocity * frameTime, 0);	
}
