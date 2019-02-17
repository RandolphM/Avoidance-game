#pragma once
#include "stdafx.h";


class Base
{
protected:
	int x;
	int y;
	ConsoleColor color;
	char* name = nullptr;

public:
	Base();
	Base(const char * const _name, ConsoleColor color);
	virtual ~Base();

	//Getters 
	int Getx() { return x; }
	int Gety() { return y; }
	ConsoleColor GetColor() const { return color; }
	const char * const GetName() const { return name; }

	

	//Setter
	void SetX(int X) { x = X; }
	void SetY(int Y) { y = Y; }
	void SetColor(ConsoleColor C) { color = C; }
	void SetName(const char * const _name);
	
	//update movement 
	virtual void Render();
	virtual void update();

};

