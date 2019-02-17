#include "stdafx.h"
#include "player.h"
#include "Enemy.h"


player::player(const char * const _name, ConsoleColor C) :Base()
{
	SetName(_name);
	SetColor(C);
}
player::player()
{
	
}

player::~player()
{
	
}


void player::render()
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor(color);
	cout << '@';
	Console::ResetColor();
}

void player::update()
{


	if (GetAsyncKeyState('W'))
		y -= 1;
	if (GetAsyncKeyState('S'))
		y += 1;
	if (GetAsyncKeyState('D'))
		x += 1;
	if (GetAsyncKeyState('A'))
		x -= 1;

	if (x < 0)
		x = 0;
	if (x > Console::WindowWidth())
		x = Console::WindowWidth() - 1;
	if (y < 0)
		y = 0;
	if (y > Console::WindowHeight())
		y = Console::WindowHeight() + 1;

}
