#include "stdafx.h"
#include "Ball.h"
#include "Bar.h"
#include "Obstacle.h"
#include "Game.h"
#include "MainMenu.h"
#include "EndScreen.h"
#include "IntroScreen.h"
#include <sstream>

using namespace sf;

bool Game::IsExiting()
{
	if(gameState == Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	switch(gameState)
	{
		case ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case ShowingIntro:
		{
			ShowIntroScreen();
			break;
		}
		case Winning:
        {
            ShowWinScreen();
            break;
        }
        case Losing:
        {
            ShowLoseScreen();
            break;
        }
		case Playing:
		{
		    /****************************** Initialization ******************************/
            bool exit = true;
		    int hitno1 = 0;
            int hitno2 = 0;
            int hitno3 = 0;
            int lives = 3;
            int speed = 1;

             // create a ball
            Ball ball(windowWidth / 2, windowHeight - 30);

            // create a bar
            Bar bar(windowWidth / 2, windowHeight - 20);

            // create an obstacle #1
            Obstacle obstacle1(0, 180, 1, Color::White);

            // create an obstacle #2
            Obstacle obstacle2(0, 130, 2, Color::Magenta);

            // create an obstacle #3
            Obstacle obstacle3(0, 80, 3, Color::Red);

            // create a text hud
            Text hud;

            // Choose a font
            Font font;
            // http://www.dafont.com/theme.php?cat=302
            font.loadFromFile("fonts/DS-DIGI.ttf");

            // Set the font
            hud.setFont(font);

            // Set the font large in size
            hud.setCharacterSize(25);

            // Choose a color
            hud.setFillColor(Color::White);

            while(exit)
            {
                /********************* Handle the player input *********************/

                Event currentEvent;
                while(mainWindow.pollEvent(currentEvent))
                {
                    if(currentEvent.type == Event::Closed)
                    {
                        gameState = Exiting;
                    }
                    else if(currentEvent.type == Event::KeyPressed)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            // Escape to main menu
                            exit = false;
                        }
                    }
                }

                if(currentEvent.type == Event::KeyPressed)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Left))
                    {
                        if(bar.getPosition().left > 0)
                        {
                            // Bar Move Left
                            bar.moveLeft();
                        }
                    }

                    else if(Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        if(bar.getPosition().left + 50 < windowWidth)
                        {
                            // Bar Move Right
                            bar.moveRight();
                        }
                    }
                }

                /*********************** Update the frame *************************/

                // Handle ball hitting the bottom
                if (ball.getPosition().top > windowHeight)
                {
                    // Reset the ball
                    ball.reset(windowWidth / 2, windowHeight - 30);

                    // Remove a life
                    lives--;

                    // Check for zero lives
                    if (lives < 1)
                    {
                        gameState = Losing;
                        exit = false;
                        ShowLoseScreen();
                    }
                }

                // Handle ball hitting top
                if (ball.getPosition().top < 0)
                {
                    gameState = Winning;
                    exit = false;
                    ShowWinScreen();
                }

                // Handle ball hitting sides
                if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
                {
                    ball.reboundSides();
                }

                // Handle ball hitting bar
                if (ball.getPosition().intersects(bar.getPosition()))
                {
                    // Hit detected so reverse the ball and score a point
                    ball.reboundBarOrObs();
                }

                // Handle ball hitting obstacle #1
                if (ball.getPosition().intersects(obstacle1.getPosition()))
                {
                    // Hit detected so reverse the ball and score a point
                    ball.reboundBarOrObs();

                    // Everytime obstacle hit, ball speed increase
                    ball.incSpeed();

                    speed++;
                    hitno1++;

                    // Hit detected so obstacle disappear in certain amount of hit
                    if(hitno1 == obstacle1.getHitNo())
                        obstacle1.disappear();
                }

                // Handle ball hitting obstacle #2
                if (ball.getPosition().intersects(obstacle2.getPosition()))
                {
                    // Hit detected so reverse the ball and score a point
                    ball.reboundBarOrObs();

                    // Everytime obstacle hit, ball speed increase
                    ball.incSpeed();

                    speed++;
                    hitno2++;

                    // Hit detected so obstacle disappear in certain amount of hit
                    if(hitno2 == obstacle2.getHitNo())
                        obstacle2.disappear();
                }

                // Handle ball hitting obstacle #3
                if (ball.getPosition().intersects(obstacle3.getPosition()))
                {
                    // Hit detected so reverse the ball and score a point
                    ball.reboundBarOrObs();

                    // Everytime obstacle hit, ball speed increase
                    ball.incSpeed();

                    speed++;
                    hitno3++;

                    // Hit detected so obstacle disappear in certain amount of hit
                    if(hitno3 == obstacle3.getHitNo())
                        obstacle3.disappear();
                }

                ball.update();
                bar.update();

                gameState = Playing;

                // Update the HUD text
                std::stringstream ss;
                ss << "   Lives:" << lives << "    Speed:" << speed << "x";
                hud.setString(ss.str());

                /****************************** Draw the frame ******************************/

                // Clear everything from the last frame
                mainWindow.clear(Color(26, 128, 182,255));

                mainWindow.draw(bar.getShape());

                mainWindow.draw(obstacle1.getShape());

                mainWindow.draw(obstacle2.getShape());

                mainWindow.draw(obstacle3.getShape());

                mainWindow.draw(ball.getShape());

                // Draw our score
                mainWindow.draw(hud);

                // Show everything we just drew
                mainWindow.display();
            }
            gameState = ShowingMenu;
            ShowMenu();
			break;
		}
	}
}

void Game::ShowIntroScreen()
{
	IntroScreen introScreen;
	introScreen.Show(mainWindow);
	gameState = ShowingMenu;
}

void Game::ShowWinScreen()
{
	EndScreen endScreen1;
	endScreen1.Show(mainWindow, true);
	gameState = Winning;
}

void Game::ShowLoseScreen()
{
	EndScreen endScreen2;
	endScreen2.Show(mainWindow, false);
	gameState = Losing;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch(result)
	{
		case MainMenu::Play:
		{
			gameState = Playing;
			break;
		}
		case MainMenu::Exit:
		{
			gameState = Exiting;
			break;
		}
	}
}

void Game::Start()
{
	if(gameState != Uninitialized)
		return;

	mainWindow.create(VideoMode(windowWidth, windowHeight),"Ball");

	gameState = ShowingIntro;

	while(!IsExiting())
	{
		GameLoop();
	}

	mainWindow.close();
}

// Static member variables need to be instantiated outside of the class
Game::GameState Game::gameState = Uninitialized;
RenderWindow Game::mainWindow;
