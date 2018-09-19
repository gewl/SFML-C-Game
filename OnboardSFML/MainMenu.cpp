#include "stdafx.h"
#include "MainMenu.h"
#include <iostream>

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Font font;
	if (!font.loadFromFile("fonts/sansation.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	std::string playString = "Play Game";
	sf::Vector2f playPosition = sf::Vector2f(100.0f, 100.0f);

	sf::Text playText;

	playText.setFont(font);
	playText.setCharacterSize(20);
	playText.setStyle(sf::Text::Bold);
	playText.setFillColor(sf::Color::Black);
	playText.setPosition(playPosition);
	playText.setString(playString);

	MenuItem playButton;
	playButton.rect = playText.getGlobalBounds();
	playButton.rect.width *= 1.2f;
	playButton.rect.height *= 1.8f;
	playButton.action = Play;

	std::string exitString = "Exit";
	sf::Vector2f exitPosition = sf::Vector2f(100.0f, 200.0f);

	sf::Text exitText;

	exitText.setFont(font);
	exitText.setCharacterSize(20);
	exitText.setStyle(sf::Text::Bold);
	exitText.setFillColor(sf::Color::Black);
	exitText.setPosition(exitPosition);
	exitText.setString(exitString);

	MenuItem exitButton;
	exitButton.rect = exitText.getGlobalBounds();
	exitButton.rect.width *= 1.2f;
	exitButton.rect.height *= 1.8f;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	window.clear(sf::Color(0, 100, 100));
	window.draw(playText);
	window.draw(exitText);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(sf::Vector2f mousePos)
{
	std::list<MenuItem>::iterator iter;

	for (iter = _menuItems.begin(); iter != _menuItems.end(); iter++)
	{
		sf::FloatRect menuItemRect = (*iter).rect;

		if (menuItemRect.contains(mousePos))
		{
			return (*iter).action;
		}
	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}