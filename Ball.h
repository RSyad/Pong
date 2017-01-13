/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball{
	private:
		Vector2f position;

		RectangleShape ballShape;

		float xVelocity = .1f;
		float yVelocity = .1f;

	public:
		Ball(float startX, float startY);

		FloatRect getPosition();

		RectangleShape getShape();

		float incSpeed();

		void reboundSides();

		void reboundBarOrObs();

		void reset(float startX, float startY);

		void update();

};
