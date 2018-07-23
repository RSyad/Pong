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
