/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

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
