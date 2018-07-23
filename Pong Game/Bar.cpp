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
