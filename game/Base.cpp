#include "stdafx.h"
#include "Base.h"
#include <ctime>


Base::Base()
{
	//Default position
	SetX(rand() % Console::WindowWidth());
	SetY(rand() % Console::WindowHeight());
}
Base::Base(const char * const _name, ConsoleColor color)
{
	SetName(_name);
	SetColor(color);
}



Base::~Base()
{
	delete[] name;
}


void Base::update()
{
	
}
void Base::SetName(const char * const _name)
{
	delete[] name;

	/*int length = strlen(_name) + 1;
	name = new char[length];
	strcpy_s(name, length, _name);*/

	name = _strdup(_name);
}
void Base::Render()
{

}


