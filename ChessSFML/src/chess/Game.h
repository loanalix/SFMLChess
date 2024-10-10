#pragma once
#include<iostream>
#include <string>

class Board;

class Game
{
public:

	Game();

	virtual ~Game();

	void InitGame();

	void GameLoop();

	bool ConvertInput(const char* input, int* posX, int* posY);

	void ChangeTurn();

private:

	Board* board;
	char m_turn;
	std::string error;

	int m_nubTurn;

};

