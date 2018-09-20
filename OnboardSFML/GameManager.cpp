#include "stdafx.h"
#include "GameManager.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include <iostream>

void GameManager::Start(void)
{
	if (_gameState != Uninitialized)
	{
		return;
	}

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Confused Ball");

	sf::IntRect playerSourceSprite(65, 192, 73, 96);
	_player.Load("images/player_spritesheet.png", playerSourceSprite);
	_player.SetPosition((1024 / 2) - 45, 300);

	_gameState = GameManager::ShowingSplash;

	while (!IsExiting())
	{
		Tick();
	}

	_mainWindow.close();
}

bool GameManager::IsExiting()
{
	return _gameState == GameManager::Exiting;
}

void GameManager::Tick()
{
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent))
	{
		switch (_gameState)
		{
		case GameManager::Uninitialized:
			break;
		case GameManager::ShowingSplash:
			ShowSplashScreen();
			break;
		case GameManager::Paused:
			break;
		case GameManager::ShowingMenu:
			ShowMenu();
			break;
		case GameManager::Playing:
			sf::Event currentEvent;

			while (_mainWindow.pollEvent(currentEvent))
			{
				_mainWindow.clear(sf::Color(0, 0, 0));
				_player.Draw(_mainWindow);
				_mainWindow.display();
				if (currentEvent.type == sf::Event::Closed)
				{
					_gameState = GameManager::Exiting;
				}
				else if (currentEvent.type == sf::Event::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Escape)
					{
						ShowMenu();
					}
				}
				break;
			}
			break;
		case GameManager::Exiting:
			_mainWindow.clear(sf::Color(0, 255, 0));
			_mainWindow.display();
			break;
		default:
			break;
		}
	}
}

void GameManager::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = GameManager::ShowingMenu;
}

void GameManager::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = GameManager::Exiting;
		break;
	case MainMenu::Play:
		_gameState = GameManager::Playing;
		break;
	default:
		break;
	}
}

GameManager::GameState GameManager::_gameState = Uninitialized;
sf::RenderWindow GameManager::_mainWindow;
PlayerCharacter  GameManager::_player;
