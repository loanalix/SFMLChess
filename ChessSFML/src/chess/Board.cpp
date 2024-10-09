#include "pch.h"
#include "Board.h"

Board::Board(){}

void Board::InitBoard(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(200, 100));

	for (int row = 0 ; row < 8 ; row++ ){
		for (int col = 0;col < 8;col++ ){
			rectangle.setPosition(sf::Vector2f(200, 100));
			if (isColor){
				rectangle.setFillColor(sf::Color::Green);
			}
			else {
				rectangle.setFillColor(sf::Color::White);
			}
			isColor = !isColor;
			window.draw(rectangle);
		}
		isColor = !isColor;
	}

}



Board::~Board(){}