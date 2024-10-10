#include"pch.h"
#include "Piece.h"


Piece::Piece() {};


void Piece::InitPiece(int posX, int posY, char symbole, int sense, char team)
{
	m_posX = posX;
	m_posY = posY;
	m_symbole = symbole;
	m_team = team;

}

int Piece::CheckMove(int moveCaseX, int moveCaseY, Board* board)
{
	return 0;
}

bool Piece::Move(int moveX, int moveY, Board* board)
{
	int checkMove = CheckMove(moveX, moveY, board);

	if (checkMove == 0) return false;

	if (checkMove == 1) {
		board->m_TabPiece[m_posX * 8 + m_posY] = nullptr;
		m_posX = moveX;
		m_posY = moveY;
		board->m_TabPiece[m_posY * 8 + m_posX] = this;

		return true;
	}

}



Piece::~Piece() {};