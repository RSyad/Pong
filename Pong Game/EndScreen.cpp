#include "stdafx.h"
#include "EndScreen.h"

void EndScreen::Show(RenderWindow& renderWindow, bool win)
{
	Texture texture1;
	if(texture1.loadFromFile("graphics/Congrats.png") != true)
	{
		return;
	}

	Texture texture2;
	if(texture2.loadFromFile("graphics/GameOver.png") != true)
	{
		return;
	}

	if(win == true)
	{
		Sprite sprite1(texture1);
		renderWindow.draw(sprite1);
		renderWindow.display();
	}
	else if(win == false)
	{
		Sprite sprite2(texture2);
		renderWindow.draw(sprite2);
		renderWindow.display();
	}

	Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == Event::KeyPressed ||
                event.type == Event::MouseButtonPressed ||
                event.type == Event::Closed )
			{
				return;
			}
		}
	}
}
