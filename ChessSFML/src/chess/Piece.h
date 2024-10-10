#pragma once

#include "Board.h"

class Board;

class Piece
{
public:
	int		m_posX;
	int		m_posY;
	char	m_symbole;
	char	m_team;


	Piece();
	virtual ~Piece();

	int virtual CheckMove(int moveCaseX, int moveCaseY, Board* board);

	void virtual InitPiece(int posX, int posY, char symbole, int sense, char team);

	bool Move(int moveX, int moveY, Board* board);
};

