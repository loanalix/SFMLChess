#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();
	virtual ~Queen();
	int HorizontaVerticallMove(int moveCaseX, int moveCaseY, Board* board);
	int DiagonalMove(int moveCaseX, int moveCaseY, Board* board);

	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

};

