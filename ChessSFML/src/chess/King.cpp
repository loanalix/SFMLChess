#include "pch.h"
#include "King.h"

void King::Init(ColorCustom c, int x, int y)
{
	icon = 'K';

	color = c;

	posX = x;
	posY = y;

	string path = "";

	if (color == White)
	{
		path = "..\\..\\..\\src\\chess\\Texture\\white_king.png";
	}
	else {
		path = "..\\..\\..\\src\\chess\\Texture\\black_king.png";
	}

	if (!texture.loadFromFile(path))
	{
		cout << "n";
		// erreur...
	}
}

bool King::Move(Piece* board[64], int pos1) {
	int y = pos1 / 8;
	int x = pos1 % 8;
	int index = posY * 8 + posX;
	int diffX = x - posX;
	int diffY = y - posY;
	int diffXAbs = abs(diffX);
	int diffYAbs = abs(diffY);

	if ((diffYAbs == 0 && diffXAbs == 1) || (diffXAbs == 0 && diffYAbs == 1) || (diffXAbs == 1 && diffYAbs == 1))
	{

		board[pos1] = board[index];
		board[index] = nullptr;

		posY = y;
		posX = x;

		return true;

	}
	return false;
}

std::list<int> King::GetPossibleMoves(Piece* board[64], int pos1)
{
	std::list<int> possibleMoves;

	int y = pos1 / 8;  // Row (y-axis)
	int x = pos1 % 8;  // Column (x-axis)

	// List of relative king moves (1 square in any direction)
	const int kingMoves[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},  // Up-left, Up, Up-right
		{0, -1},          {0, 1},     // Left,        Right
		{1, -1}, {1, 0}, {1, 1}       // Down-left, Down, Down-right
	};

	// Check all 8 possible king moves
	for (int i = 0; i < 8; ++i)
	{
		int newY = y + kingMoves[i][0];
		int newX = x + kingMoves[i][1];
		int newPos = newY * 8 + newX;

		// Check if the move is within the bounds of the board
		if (newY >= 0 && newY < 8 && newX >= 0 && newX < 8)
		{
			// Check if the square is empty or contains an opponent's piece
			if (board[newPos] == nullptr || board[newPos]->color != this->color)
			{
				// You would typically add additional logic here to ensure that 
				// moving to newPos does not place the King in check.
				possibleMoves.push_back(newPos);
			}
		}
	}

	return possibleMoves;
}