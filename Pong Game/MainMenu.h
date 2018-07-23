#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

using namespace sf;

class MainMenu
{
    public:
		enum MenuResult { Menu, Play, Exit };

		struct MenuItem
		{
			IntRect rect;
			MenuResult action;
		};

		MenuResult Show(RenderWindow& window);

	private:
		MenuResult GetMenuResponse(RenderWindow& window);
		MenuResult HandleClick(int x, int y);
		std::list<MenuItem> menuItems;
};
