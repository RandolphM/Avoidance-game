#include "stdafx.h"
#include "powerup.h"


powerup::powerup()
{
}


powerup::~powerup()
{
}

void powerup::Render()
{
	Console::ForegroundColor(Cyan);
	Console::SetCursorPosition(x, y);
	cout << "%";
	Console::ResetColor();
	
}
