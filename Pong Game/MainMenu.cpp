#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(RenderWindow& window)
{
	//Load menu image from file
	Texture texture;
	texture.loadFromFile("graphics/Menu.png");
	Sprite sprite(texture);

	/*******************Setup clickable regions*******************/

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top= 100;
	playButton.rect.height = 140;
	playButton.rect.left = 0;
	playButton.rect.width = 639;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 639;
	exitButton.rect.top = 145;
	exitButton.rect.height = 350;
	exitButton.action = Exit;

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = menuItems.begin(); it != menuItems.end(); it++)
	{
		IntRect menuItemRect = (*it).rect;
		if( x > menuItemRect.left
            && x < menuItemRect.left + menuItemRect.width
            && y > menuItemRect.top
            && y < menuItemRect.height + menuItemRect.top)
        {
            return (*it).action;
        }
	}

	return Menu;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(RenderWindow& window)
{
	Event menuEvent;

	while(42 != 43)
	{

		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			}
			if(menuEvent.type == Event::Closed)
			{
				return Exit;
			}
		}
	}
}
