#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:

	Knight();
	~Knight();
	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

};

