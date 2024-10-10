#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King();
	~King();
	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

};

