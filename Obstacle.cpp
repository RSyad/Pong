/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

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
