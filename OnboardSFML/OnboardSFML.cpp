// OnboardSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

int main(int argc, char ** argv)
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML Demo");

	sf::Event event;
	sf::Texture texture;
	texture.loadFromFile("image.png");

	sf::Sprite sprite(texture);

    while (renderWindow.isOpen())
    {
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}
		}

		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.display();
    }
}

