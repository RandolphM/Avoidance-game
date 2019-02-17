#include "stdafx.h"
#include "Enemy.h"
#include <ctime>


Enemy::Enemy() : Base()
{

}


Enemy::~Enemy()
{

}

void Enemy::update()
{
	
	int randnum = rand();
	
	if (randnum % 4 == 0)
		x += 1;
	else if (randnum % 4 == 1)
		x -= 1;
	else if (randnum % 4 == 2)
		y += 1;
	else if (randnum % 4 == 3)
		y -= 1;


	if (x < 0)
		x = Console::WindowWidth();
	if (x > Console::WindowWidth())
		x = 0;
	if (y < 0)
		y = Console::WindowHeight() + 2;
	if (y > Console::WindowHeight())
		y = 0;


}

void Enemy::render()
{
	Base::GetColor();
	Console::ForegroundColor(Red);
	char symbol = 'X';
	Console::SetCursorPosition(Base::Getx(), Base::Gety());
	cout << symbol;
	Console::ForegroundColor(Gray);
}


