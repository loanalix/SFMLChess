#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook();
	~Rook();

	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

};

