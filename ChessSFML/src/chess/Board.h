#pragma once
#include "pch.h"

class Board
{
private:

	bool isColor;


public:
	Board();
	virtual ~Board();
	
	void InitBoard(sf::RenderWindow& window);

};

