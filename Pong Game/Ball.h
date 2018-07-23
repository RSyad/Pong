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
