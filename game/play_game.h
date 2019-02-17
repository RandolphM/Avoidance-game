#pragma once
class play_game
{
	int currente = 0;
	int current = 0;
	int score = 0;
	int time = 0;
	
	
public:

	~play_game();

	//game to run from the menu
	void rungameMenu();
	void rungame();

	//file input
	void Loadscores();
	
};

