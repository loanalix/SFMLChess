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
#ifdef _WINDOW
sf::Texture texture;

#endif // _WINDOW


	virtual bool Move(Piece* board[64], int pos1);
	virtual std::list<int> GetPossibleMoves(Piece* board[64], int pos1);
};
