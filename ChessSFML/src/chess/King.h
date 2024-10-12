#pragma once

class King : public Piece
{
public:
	King() {};
	~King() {};

	std::list<int> GetPossibleMoves(Piece* board[64], int pos1);
	void Init(ColorCustom c, int x, int y) override;
};
