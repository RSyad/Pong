#pragma once

using namespace sf;

class EndScreen
{
	private:
		bool win;
	public:
		void Show(RenderWindow& window, bool win);
};
