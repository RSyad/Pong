/********************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2016/17
ID and Name #1 : 1142700937 Arsyad bin Anuar
Contacts #1 : 019-3456645 rsyad126@gmail.com
********************************************/

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
