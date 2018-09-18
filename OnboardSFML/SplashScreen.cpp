#include "stdafx.h"
#include <iostream>
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& window)
{
	sf::Font font;

	if (!font.loadFromFile("fonts/sansation.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	sf::Text text;

	std::string titleString = "Welcome to Computer Game";

	text.setFont(font);
	text.setCharacterSize(20);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setPosition(100, 100);
	text.setString(titleString);

	sf::Color color;
	color = sf::Color(0, 100, 100);
	window.clear(color);
	window.draw(text);
	window.display();

	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}