#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	try
	{
		Game game;
		game.Start();
	}
	catch(std::runtime_error e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
