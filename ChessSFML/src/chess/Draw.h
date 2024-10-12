#pragma once

class Draw
{
public:
	Draw() {};
	~Draw() {};

#ifdef _CONSOLE 

	void DrawBoard(Piece** board, int indexChoice, list<int> possibleMove);

#endif // _CONSOLE 

#ifndef _CONSOLE

	void DrawBoard(Piece** board, RenderWindow* render, int indexChoice, list<int> possibleMove);

	Color ColorWhite = Color(255, 255, 255);

	Color ColorBlack = Color(0, 0, 0);


#endif // !_CONSOLE

	void DrawBoardPossibleMove(Piece** board, list<int> possibleMove);
	void Reset();

	int initX = 50;
	int initY = 50;

};