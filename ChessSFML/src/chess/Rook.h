#pragma once

class Rook : public Piece
{
public:
	Rook() {};
	~Rook() {};

	bool Move(Piece* board[64], int pos1) override;
	std::list<int> GetPossibleMoves(Piece* board[64], int pos1) override;
	void Init(ColorCustom c, int x, int y) override;
};

