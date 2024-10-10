#include"pch.h"
#include "King.h"

King::King() {}

int King::CheckMove(int moveCaseX, int moveCaseY, Board* board) {

    int deltaX = abs(moveCaseX - m_posX);
    int deltaY = abs(moveCaseY - m_posY);

    // V�rifier si le mouvement est valide (1 case dans n'importe quelle direction)
    if ((deltaX <= 1 && deltaY <= 1) && !(deltaX == 0 && deltaY == 0)) {
        // V�rifier si la case de destination est occup�e par une pi�ce de la m�me �quipe
        Piece* destinationPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
        if (destinationPiece == nullptr || destinationPiece->m_team != m_team) {
            return 1; // Mouvement valide
        }
    }

    return 0; // Mouvement invalide
}


King::~King() {}