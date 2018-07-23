#include "stdafx.h"
#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
	ballShape.setSize(Vector2f(10, 10));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::incSpeed()
{
    if(xVelocity > 0)
        xVelocity += .1f;
    else if(yVelocity > 0)
        yVelocity += .1f;
    else if(xVelocity < 0)
        xVelocity -= .1f;
    else if(yVelocity < 0)
        yVelocity -= .1f;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBarOrObs()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::reset(float startX, float startY)
{
    yVelocity = -yVelocity;
	position.x = startX;
    position.y = startY;
	ballShape.setPosition(position);
}

void Ball::update()
{
	//Update the ball position variables
	position.y += yVelocity;
	position.x += xVelocity;

	//Move the ball and the bar
	ballShape.setPosition(position);
}
