#pragma once

class Bishop : public Piece
{
public:
	Bishop() {};
	~Bishop() {};


	void Init(ColorCustom c, int x, int y) override;

	std::list<int> GetPossibleMoves(Piece* board[64], int pos1);
};