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
