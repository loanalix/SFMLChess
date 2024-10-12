#pragma once
#include "list"
#include "Queen.h"

class Pawn : public Piece
{
public:
	Pawn() {};
	~Pawn() {};

	std::list<int> GetPossibleMoves(Piece* board[64], int pos1) override;
	void Init(ColorCustom c, int x, int y) override;
	void MoveCode(Piece* board[64], int pos1);
	void SpecialMove(Piece* board[64], int pos1);

	bool isFirstMove = true;
	bool isQueen = false;

	Queen queen;
};

