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

	PlayerCharacter *player = new PlayerCharacter();
	player->SetPosition((1024 / 2) - 45, 300);

	_gameObjectManager.Add("Player", player);

	GrassSquare *terrain = new GrassSquare();
	terrain->SetPosition((1024 / 2) - 45, 500);

	_staticGameObjectManager.Add("Terrain1", terrain);
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

sf::RenderWindow& GameManager::GetWindow()
{
	return _mainWindow;
}

void GameManager::Tick()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	sf::Time frameTime = clock.restart();

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
		_mainWindow.clear(sf::Color(0, 0, 0));
		_gameObjectManager.UpdateAll(frameTime);
		_gameObjectManager.DrawAll(_mainWindow);
		_staticGameObjectManager.DrawAll(_mainWindow);
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
	case GameManager::Exiting:
		_mainWindow.clear(sf::Color(0, 255, 0));
		_mainWindow.display();
		break;
	default:
		break;
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
GameObjectManager GameManager::_gameObjectManager;
StaticGameObjectManager GameManager::_staticGameObjectManager;
sf::Clock GameManager::clock;
