// OnboardSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main(int argc, char ** argv)
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML Demo");

	sf::Event event;

	bool shouldDraw = false;
    while (renderWindow.isOpen())
    {
		// Check for events since last frame
		while (renderWindow.pollEvent(event))
		{
			// Handle events
			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}
			else if (event.type == sf::Event::EventType::KeyPressed)
			{
				shouldDraw = true;
			}

		}

		renderWindow.clear();
		if (shouldDraw)
		{
			sf::Vector2f rectangleSize(20.0f, 25.0f);
			sf::RectangleShape shape(rectangleSize);
			shape.setFillColor(sf::Color::Red);

			renderWindow.draw(shape);
		}
		renderWindow.display();
    }
}

