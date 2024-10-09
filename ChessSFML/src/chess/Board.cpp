#include "pch.h"
#include "Board.h"

Board::Board(){}


void Board::InitBoard(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));  // Taille de chaque case de l'échiquier
    bool isColor = true;  // On démarre avec une couleur

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            // Positionnement du rectangle
            rectangle.setPosition(sf::Vector2f(col * 100, row * 100));

            // Alterner les couleurs
            if (isColor)
            {
                rectangle.setFillColor(sf::Color::Black);
            }
            else
            {
                rectangle.setFillColor(sf::Color::White);
            }
            isColor = !isColor;  // Inverser la couleur

            // Dessiner le rectangle
            window.draw(rectangle);
        }
        isColor = !isColor;  // Alterner les couleurs à chaque nouvelle rangée
    }
}



Board::~Board(){}