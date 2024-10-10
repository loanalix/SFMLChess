#include "pch.h"
#include "Board.h"
#include "Pawn.h"
#include "TextureManager.h"

Board::Board(){}


void Board::InitBoard(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));  // Taille de chaque case de l'échiquier
    bool isColor = true;  // On démarre avec une couleur

    for (int i = 0; i < 64; i++) {
        m_TabPiece[i] = nullptr;
    }

    Pawn* pawn = new Pawn();
    pawn->InitPiece(0, 1, 'P', 1, 'w'); // Exemple de pion blanc
    m_TabPiece[1 * 8 + 0] = pawn;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {

            rectangle.setPosition(sf::Vector2f(col * 100, row * 100));

            if (isColor)
            {
                rectangle.setFillColor(sf::Color::Black);
            }
            else
            {
                rectangle.setFillColor(sf::Color::White);
            }
            isColor = !isColor;  

            window.draw(rectangle);
        }
        isColor = !isColor;  
    }
}

void Board::Draw(sf::RenderWindow& window)
{

    InitBoard(window); 

    for (auto& sprite : m_sprites) {
        window.draw(sprite);  
    }
}


Board::~Board(){}

