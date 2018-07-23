#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

using namespace sf;

class Game
{
	private:
		static const int windowWidth = 640;
		static const int windowHeight = 480;

		enum GameState { Uninitialized, ShowingIntro,
						ShowingMenu, Playing, Exiting,
						Winning, Losing };

		static GameState gameState;
		static RenderWindow mainWindow;

	public:
		static bool IsExiting();
		static void GameLoop();

		static void ShowIntroScreen();
		static void ShowMenu();
		static void ShowWinScreen();
		static void ShowLoseScreen();

		static void Start();
};
