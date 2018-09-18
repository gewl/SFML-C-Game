#include "stdafx.h"
#include "GameManager.h"
#include "SplashScreen.h"
#include <iostream>

void GameManager::Start(void)
{
	if (_gameState != Uninitialized)
	{
		return;
	}

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Confused Ball");
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
			break;
		case GameManager::Playing:
			_mainWindow.clear(sf::Color(255, 0, 0));
			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				_gameState = GameManager::Exiting;
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
}

GameManager::GameState GameManager::_gameState = Uninitialized;
sf::RenderWindow GameManager::_mainWindow;
