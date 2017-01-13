/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

#include "stdafx.h"
#include "Bar.h"

//Constructor
Bar::Bar(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
	barShape.setSize(Vector2f(50,5));
	barShape.setPosition(position);
}

FloatRect Bar::getPosition()
{
	return barShape.getGlobalBounds();
}

RectangleShape Bar::getShape()
{
	return barShape;
}

void Bar::moveLeft()
{
	position.x -= barSpeed;
}

void Bar::moveRight()
{
	position.x += barSpeed;
}

void Bar::update()
{
	barShape.setPosition(position);
}
