#pragma once
#include "Board.h"
#include "Draw.h"

class Game
{
public:
	Game() {};
	~Game() {};
	void Init(RenderWindow* r);
	int ConvertToPosition(char text[2]);
	void MakeMove(int x, int y);
	void GameLoop();
	ColorCustom player = White;
	RenderWindow* render;

	Board board;
	bool isGame = true;
	int move = -1;

	int index1 = -1;
	int index2 = -1;

	list<int> possibleMove = list<int>();
};

