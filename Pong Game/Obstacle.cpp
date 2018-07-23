#include "stdafx.h"
#include "Obstacle.h"

//Constructor
Obstacle::Obstacle(float startX, float startY, int hitno, Color colour)
{
    this->hitno = hitno;
    position.x = startX;
    position.y = startY;
	obstacleShape.setSize(Vector2f(640,5));
	obstacleShape.setPosition(position);
	obstacleShape.setFillColor(colour);
}

FloatRect Obstacle::getPosition()
{
	return obstacleShape.getGlobalBounds();
}

RectangleShape Obstacle::getShape()
{
	return obstacleShape;
}

int Obstacle::getHitNo()
{
	return hitno;
}

void Obstacle::disappear()
{
    obstacleShape.setSize(Vector2f(0,0));
}
