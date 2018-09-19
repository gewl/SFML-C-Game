#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class MainMenu {
public:
	enum MenuResult { Nothing, Exit, Play };
	struct MenuItem {
		public:
			sf::FloatRect rect;
			MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(sf::Vector2f mousePos);
	std::list<MenuItem> _menuItems;
};
