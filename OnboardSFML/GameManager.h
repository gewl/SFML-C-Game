#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerCharacter.h"
#include "GrassSquare.h"
#include "GameObjectManager.h"
#include "StaticGameObjectManager.h"

class GameManager
{
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static sf::Clock clock;
	static bool IsExiting();
	static void Tick();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState { 
		Uninitialized, 
		ShowingSplash, 
		Paused, 
		ShowingMenu, 
		Playing, 
		Exiting 
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
	static StaticGameObjectManager _staticGameObjectManager;
};
