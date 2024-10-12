#pragma once
#include "list"

class Piece
{
private:

public:

	Piece() {};
	~Piece() {};
	virtual void Init(ColorCustom c, int x, int y);

	int posX;
	int posY;
	char icon;
	ColorCustom color;

#ifndef _CONSOLE 

	sf::Texture texture;

#endif // !_CONSOLE 


	virtual std::list<int> GetPossibleMoves(Piece* board[64], int pos1);
};
