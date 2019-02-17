#pragma once
#include "Base.h"
class Enemy :
	public Base

{
	//int x;
	//int y;
	
public:
	Enemy();
	~Enemy();

	//render and update the enemy
	void update();
	void render();
};

