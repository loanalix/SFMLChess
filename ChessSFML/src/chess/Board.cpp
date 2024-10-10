#include "pch.h"
#include "Board.h"

void Board::Init()
{
	InitBoard();
}

#ifdef _LIGHT

void Board::InitBoard()
{
	for (int y = 0; y < 8; y++)
	{

		for (int x = 0; x < 8; x++)
		{
			int index = y * 8 + x;
			board[index] = nullptr;
			if (y == 0 || y == 1)
			{
				Pawn* pawn = new Pawn();
				CreatePiece(pawn, White, x, y, index);
			}
			else if (y == 6 || y == 7)
			{
				Pawn* pawn = new Pawn();
				CreatePiece(pawn, Black, x, y, index);
			}
			else {
				board[index] = nullptr;
			}

			//Queen
			if (index == 4)
			{
				Queen* queen = new Queen();
				CreatePiece(queen, White, x, y, index);
			}
			else if (index == 60)
			{
				Queen* queen = new Queen();
				CreatePiece(queen, Black, x, y, index);
			}

			//King
			else if (index == 3)
			{
				King* king = new King();
				CreatePiece(king, White, x, y, index);
			}
			else if (index == 59)
			{
				King* king = new King();
				CreatePiece(king, Black, x, y, index);
			}
		}
	}
}
#endif

#ifndef _LIGHT

void Board::InitBoard()
{
	for (int y = 0; y < 8; y++)
	{

		for (int x = 0; x < 8; x++)
		{
			int index = y * 8 + x;
			board[index] = nullptr;
			if (y == 0 || y == 1)
			{
				Pawn* pawn = new Pawn();
				CreatePiece(pawn, White, x, y, index);
			}
			else if (y == 6 || y == 7)
			{
				Pawn* pawn = new Pawn();
				CreatePiece(pawn, Black, x, y, index);
			}
			else {
				board[index] = nullptr;
			}

			//Knight
			if (index == 1 || index == 6)
			{
				Knight* knight = new Knight();
				CreatePiece(knight, White, x, y, index);
			}
			else if (index == 62 || index == 57)
			{
				Knight* knight = new Knight();
				CreatePiece(knight, Black, x, y, index);
			}

			//Rook
			else if (index == 0 || index == 7)
			{
				Rook* rook = new Rook();
				CreatePiece(rook, White, x, y, index);
			}
			else if (index == 63 || index == 56)
			{
				Rook* rook = new Rook();
				CreatePiece(rook, Black, x, y, index);
			}

			//Bishop
			else if (index == 2 || index == 5)
			{
				Bishop* bishop = new Bishop();
				CreatePiece(bishop, White, x, y, index);
			}
			else if (index == 61 || index == 58)
			{
				Bishop* bishop = new Bishop();
				CreatePiece(bishop, Black, x, y, index);
			}

			//Queen
			else if (index == 4)
			{
				Queen* queen = new Queen();
				CreatePiece(queen, White, x, y, index);
			}
			else if (index == 60)
			{
				Queen* queen = new Queen();
				CreatePiece(queen, Black, x, y, index);
			}

			//King
			else if (index == 3)
			{
				King* king = new King();
				CreatePiece(king, White, x, y, index);
			}
			else if (index == 59)
			{
				King* king = new King();
				CreatePiece(king, Black, x, y, index);
			}
		}
	}
}

#endif


void Board::CreatePiece(Piece* piece, ColorCustom color, int x, int y, int index) {
	piece->Init(color, x, y);
	piece->color = color;
	piece->posX = x;
	piece->posY = y;
	board[index] = piece;
}