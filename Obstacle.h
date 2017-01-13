/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacle
{
	private:
		Vector2f position;
        int hitno;
		//A RectangleShape object
		RectangleShape obstacleShape;

	public:
		Obstacle(float startX, float startY, int hitno, Color colour);

		FloatRect getPosition();

		RectangleShape getShape();

		int getHitNo();

		void disappear();
};
