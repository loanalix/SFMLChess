#pragma once
#include "vector"

using namespace std;

class Board
{

public:
	Board() {};
	~Board() {};
	void Init();
	void InitBoard();
	void CreatePiece(Piece* piece, ColorCustom color, int x, int y, int index);
	Piece* board[64];
};
