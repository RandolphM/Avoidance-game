#include "stdafx.h"
#include "play_game.h"
#include "Enemy.h"
#include "player.h"
#include "powerup.h"
#include <fstream>



play_game::~play_game()
{

}


void play_game::rungameMenu() 
{
	system("cls");
	while (true)
	{
		int option;
		Console::Clear();
		Console::CursorVisible(true);
		Console::SetCursorPosition(0, 0);
		cout << "1) Start Game\n";
		cout << "2) See scores before\n";
		cout << "3) Quit\n";
		cout << "What is your Selection? : ";
		while (true)
		{
			if (cin >> option && option <= 3 && option >= 1)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Enter a number(1-3) please, so we can play jerk: ";
			}
		}
		if (option == 1)
		{
			rungame();
		}
		if (option == 2)
		{
			Loadscores();
		}
		if (option == 3)
		{
			cout << "Thanks for Playing\n";
			cout << "If you didn't play, your no fun\n";
			Console::SetCursorPosition(0, Console::WindowHeight());
			system("pause");
			break;
		}
	}
}

void play_game::rungame()
{
	int nump = 0;
	int colorchoise;
	int save_option = 0;
	int enemy_spawn_speed = 200;
	int powerup_spwan_speed = 400;
	char buffer[35];
	int power = 0;
	ConsoleColor playerc;
	vector<player*> players;
	vector<Enemy*> enemies;
	vector<powerup*> powers;
	vector<int> scores;
	decltype(players.size()) i = 0;
	decltype(enemies.size()) e;
	cout << "How many Players: ";
	while (true)
	{
		if (cin >> nump)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter a numeric value please, and stop being a jerk: ";
		}
	}

	players.resize(nump);
	enemies.resize(400);
	powers.resize(400);
	scores.resize(nump);

	for (; i < players.size(); ++i)
	{
		Console::Clear();
		cout << "What is player" << i + 1 << " name: ";
		cin >> buffer;
		cin.ignore(INT_MAX, '\n');
		cout << "What color you want the player?\n";
		cout << "1) Blue\n";
		cout << "2) Yellow\n";
		cout << "3) White\n";
		cout << "4) Green\n";
		cout << "Selection: ";
		if (cin >> colorchoise && colorchoise <= 4 && colorchoise >= 1)
		{
			//break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter a number(1-4) please, so we can play jerk: ";
		}
		if (colorchoise == 1)
			playerc = Blue;
		else if (colorchoise == 2)
			playerc = Yellow;
		else if (colorchoise == 3)
			playerc = White;
		else if (colorchoise == 4)
			playerc = Green;

		players[i] = new player(buffer, playerc);
	}

	
	cout << "\nGet Ready to play!!\n";
	system("pause");
	system("cls");
	current = 0;
	Console::CursorVisible(false);
	if (PlaySound(TEXT("Pertussis Sinusitis (Dr. Mario Chill) - Harmony Of Heroes.wav"), NULL, SND_FILENAME | SND_ASYNC))
	{
		while (current != players.size())
		{
			Console::Lock(true);
			Console::Clear();
			players[current]->update();
			players[current]->render();
			for (e = 0; e < currente; ++e)
			{
				enemies[e]->update();
				enemies[e]->render();
			}
			for (unsigned int p = 0; p < power; ++p)
			{
				powers[p]->Render();
			}
			for (e = 0; e < currente; ++e)
			{
				if (players[current]->Getx() == enemies[e]->Getx() && players[current]->Gety() == enemies[e]->Gety())
				{
					Console::Clear();
					for (e = 0; e < currente; ++e)
						delete enemies[e];
					for (unsigned int p = 0; p < power; ++p)
						delete powers[p];
					Console::SetCursorPosition(players[current]->Getx(), players[current]->Gety());
					cout << "X_X";
					scores[current] = score;
					current++;
					power = 0;
					currente = 0;
					time = 0;
					score = 0;
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("Pertussis Sinusitis (Dr. Mario Chill) - Harmony Of Heroes.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			
			if (power != 0)
			{
				for (unsigned int p = 0; p < power; ++p)
				{
					if (players[current]->Getx() == powers[p]->Getx() && players[current]->Gety() == powers[p]->Gety())
					{
						Console::Clear();
						for (e = 0; e < currente; ++e)
							delete enemies[e];
						for (unsigned int p = 0; p < power; ++p)
							delete powers[p];
						Console::SetCursorPosition(players[current]->Getx(), players[current]->Gety());
						power = 0;
						currente = 0;
						score += 5;
						enemy_spawn_speed -= 10;
					}
				}
			}
		
			Console::SetCursorPosition(0, Console::WindowHeight());
			cout << " Score: " << score << " Time: " << time;
			Console::Lock(false);
			Sleep(20);
			score += 1;
			time += 1;
			if (time % enemy_spawn_speed == 0)
			{
				enemies[currente] = new Enemy();
				currente++;
			}
			if (time % powerup_spwan_speed == 0)
			{
			    powers[power] = new powerup();
				power++;
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				for (e = 0; e < currente; ++e)
					delete enemies[e];
				for (unsigned int p = 0; p < power; ++p)
					delete powers[p];
				break;
			}
		}
		PlaySound(NULL, 0, 0);
	}
	Console::Clear();
	Console::CursorVisible(true);
	Console::SetCursorPosition(0, 0);
	cout << "Scorebored: \n";
	for (i = 0; i < players.size(); ++i)
	{
		cout << i + 1 << ") player: " << players[i]->GetName() << " score: " << scores[i] << "\n";
	}
	cout << "\n";
	system("pause");
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "\n1) Yes\n";
	cout << "2) No\n";
	cout << "Do you want to save these scores: ";
	while (true)
	{
		if (cin >> save_option && save_option <= 2 && save_option >= 1)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter a number(1-2) please, so we can play jerk: ";
		}
	}
	
	if (save_option == 1)
	{
		char fileName[32];
		char RealFile[32];
		Console::Clear();
		cout << "What type of file to save?\n";
		cout << "1) Text\n";
		cout << "2) Binary\n";
		cout << "selection: ";
		int type_option = 0;
		while (true)
		{
			if (cin >> type_option && type_option <= 2 && type_option >= 1)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Enter a number(1-2) please, so we can play jerk: ";
			}
		}
		if (type_option == 1) 
		{
			cout << "\nWhat would like to name the file(Don't forget the .txt plaese): ";
			cin >> fileName;

			fstream save;
			save.open(fileName, ios_base::out | ios_base::app);
			if (save.is_open())
			{
				for (i = 0; i < players.size(); ++i)
				{
					save << i + 1 << ") player: " << players[i]->GetName() << " score: " << scores[i] << "\n";
					
				}
				save.close();
			}
			else
				cout << "File did not open";
		}
		else if (type_option == 2)
		{
			ofstream bout;
			bout.open("players.bin", ios_base::binary);
			if (bout.is_open())
			{
				bout.write((char*)players.data(), sizeof(player) * players.size());
				bout.close();
			}
			else
				cout << "File did not open";
			
			ofstream out;
			out.open("scores.bin", ios_base::binary);
			if (out.is_open())
			{
				out.write((char*)scores.data(), sizeof(int) * scores.size());
				out.close();
			}
			else
				cout << "File did not open";
		}
	}
	else
	{
		cout << "Hope you play again\n";
		cout << "See you later";
		Console::SetCursorPosition(0, Console::WindowHeight());
		system("pause");
	}

	for (i = 0; i < players.size(); ++i)
		delete players[i];
	
}
void play_game::Loadscores()
{
	vector<int> scores;
	fstream bin;
	bin.open("scores.bin", ios_base::binary | ios_base::in);

	if (!bin.is_open())
	{
		cout << "Busted";
		return;
	}
	bin.seekg(0, ios_base::end);
	int count = bin.tellg();
	count /= sizeof(int);
	bin.seekg(0, ios_base::beg);
	scores.resize(count);

	bin.read((char*)scores.data(), sizeof(int) * scores.size());

	cout << "Previous scores\n";
	unsigned int i = 0;
	for (; i < scores.size(); ++i)
	{
		cout << i + 1 << ")" << scores[i] << "\n";
	}
	bin.close();
	cout << "\n";
	system("pause");
}

