#pragma once
#include "pch.h"
#include "Piece.h"


class Piece;

class Board
{
public:
    Board();
    ~Board();
    
    Piece* m_TabPiece[64];

    void InitBoard(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window); 

private:
    std::vector<sf::Sprite> m_sprites; 
};

