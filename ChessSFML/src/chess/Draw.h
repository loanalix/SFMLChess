#pragma once

class Draw
{
public:
	Draw() {};
	~Draw() {};

	void DrawBoardPossibleMove(Piece** board, list<int> possibleMove);
	void Reset();

	int initX = 50;
	int initY = 50;


#ifdef _WINDOW
	void DrawBoard(Piece** board, RenderWindow* render, int indexChoice, list<int> possibleMove);

#endif // 


};