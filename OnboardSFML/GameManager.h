#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class GameManager
{
public:
	static void Start();

private:
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
};
