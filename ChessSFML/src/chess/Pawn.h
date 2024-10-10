#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	virtual ~Pawn();

	bool firstTurn;

	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;
	void  InitPiece(int posX, int posY, char symbole, int sense, char team) override;
};

