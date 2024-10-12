#include "pch.h"
#include "Knight.h"

void Knight::Init(ColorCustom c, int x, int y)
{
	icon = 'N';

	color = c;

	posX = x;
	posY = y;
#ifndef _CONSOLE 
	string path = "";

	if (color == White)
	{
		path = "..\\..\\..\\src\\chess\\Texture\\white_knight.png";
	}
	else {
		path = "..\\..\\..\\src\\chess\\Texture\\black_knight.png";
	}

	if (!texture.loadFromFile(path))
	{
		cout << "n";
		// erreur...
	}
#endif // !_CONSOLE
}

std::list<int> Knight::GetPossibleMoves(Piece* board[64], int pos1)
{
	std::list<int> possibleMoves;

	int y = pos1 / 8;  // Row (y-axis)
	int x = pos1 % 8;  // Column (x-axis)

	// List of relative knight moves (2 squares in one direction, 1 square perpendicular)
	const int knightMoves[8][2] = {
		{-2, -1}, {-2, 1},   // Move 2 up, 1 left / right
		{2, -1}, {2, 1},     // Move 2 down, 1 left / right
		{-1, -2}, {-1, 2},   // Move 1 up/down, 2 left / right
		{1, -2}, {1, 2}      // Move 1 down/up, 2 left / right
	};

	// Check all 8 possible knight moves
	for (int i = 0; i < 8; ++i)
	{
		int newY = y + knightMoves[i][0];
		int newX = x + knightMoves[i][1];
		int newPos = newY * 8 + newX;

		// Check if the move is within the bounds of the board
		if (newY >= 0 && newY < 8 && newX >= 0 && newX < 8)
		{
			if (board[newPos] == nullptr)  // Empty square
			{
				possibleMoves.push_back(newPos);
			}
			else if (board[newPos]->color != this->color)  // Opponent's piece
			{
				possibleMoves.push_back(newPos);
			}
		}
	}

	return possibleMoves;
}