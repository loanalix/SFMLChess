#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop();
	virtual ~Bishop();


	int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

};

