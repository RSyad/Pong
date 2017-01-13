
/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bar
{
	private:
		Vector2f position;

		//A RectangleShape object
		RectangleShape barShape;

		float barSpeed = .8f;

	public:
		Bar(float startX, float startY);

		FloatRect getPosition();

		RectangleShape getShape();

		void moveLeft();

		void moveRight();

		void update();

};
