#pragma once
#include "pch.h"


class Piece;

class Board
{
private:

	bool isColor;


public:
	Board();
	virtual ~Board();
	
	void InitBoard(sf::RenderWindow& window);


	Piece* m_TabPiece[64];

	void BoardPrint();


	void PlayGame();

};

