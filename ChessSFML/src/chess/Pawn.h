#pragma once

#include "Piece.h"
#include "Board.h"
class Pawn : public Piece
{
public:
    Pawn();
    ~Pawn();

    void InitPiece(int posX, int posY, char symbole, int sense, char team) override;
    int CheckMove(int moveCaseX, int moveCaseY, Board* board) override;

    void SetTexture(const sf::Texture& texture); 
    sf::Sprite& GetSprite(); 

private:
    bool firstTurn;
    sf::Sprite m_sprite; 
};

