// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "play_game.h";
#include <ctime>

void Displaytitle();

int main()
{
	srand((int)time(0));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	Console::SetWindowSize(100, 50);
	Console::SetBufferSize(100, 50);
	Displaytitle();

	play_game* game = new play_game();
	game->rungameMenu();

	delete game;

	cout << "\n\n\n\n";
    return 0;
}

void Displaytitle()
{
	char title[32] = "Welcome to Enemy MAYHEM";
	Console::SetCursorPosition(Console::WindowWidth() / 2 - (32 / 3), Console::WindowHeight() / 2);
	cout << title;
	Console::SetCursorPosition(0, Console::WindowHeight());
	system("pause");
}