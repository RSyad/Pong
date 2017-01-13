/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

#include "stdafx.h"
#include "IntroScreen.h"

using namespace sf;

void IntroScreen::Show(RenderWindow & renderWindow)
{
	Texture texture;
	if(texture.loadFromFile("graphics/IntroScreen.png") != true)
	{
		return;
	}

	Sprite sprite(texture);

	renderWindow.draw(sprite);
	renderWindow.display();

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
