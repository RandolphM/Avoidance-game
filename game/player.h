#pragma once
#include "stdafx.h"
#include "Base.h"
class player :
	public Base

{
	/*int x = Console::WindowWidth() / 2;
	int y = Console::WindowHeight() / 2;*/
	//ConsoleColor color;
	//char* name;
	

public:
	player();
	player(const char * const _name, ConsoleColor C);
	~player();

	//movement for player
	void render();
	void update();
	
};

