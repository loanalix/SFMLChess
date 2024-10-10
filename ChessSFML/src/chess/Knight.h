#pragma once

class Knight : public Piece
{
public:
	Knight() {};
	~Knight() {};

	bool Move(Piece* board[64], int pos1) override;
	std::list<int> GetPossibleMoves(Piece* board[64], int pos1);
	void Init(ColorCustom c, int x, int y) override;
};
