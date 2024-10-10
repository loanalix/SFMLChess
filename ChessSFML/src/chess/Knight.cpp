#include"pch.h"
#include "Knight.h"

Knight::Knight() {}

int Knight::CheckMove(int moveCaseX, int moveCaseY, Board* board) {
    int deltaX = abs(moveCaseX - m_posX);
    int deltaY = abs(moveCaseY - m_posY);

    // V�rifier si le mouvement est valide (2 cases dans une direction et 1 dans l'autre)
    if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {
        // V�rifier si la case de destination est occup�e par une pi�ce de la m�me �quipe
        Piece* destinationPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
        if (destinationPiece == nullptr || destinationPiece->m_team != m_team) {
            return 1; // Mouvement valide
        }
    }

    return 0; // Mouvement invalide
}

Knight::~Knight() {}