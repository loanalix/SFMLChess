#include"pch.h"
#include "Bishop.h"
#include "Board.h"

Bishop::Bishop() {}

int Bishop::CheckMove(int moveCaseX, int moveCaseY, Board* board) {
    int deltaX = moveCaseX - m_posX;
    int deltaY = moveCaseY - m_posY;

    // Vérification si le mouvement est diagonal
    if (abs(deltaX) != abs(deltaY) || (deltaX == 0 && deltaY == 0)) {
        return 0; // Mouvement invalide
    }

    int stepX = (deltaX > 0) ? 1 : -1;
    int stepY = (deltaY > 0) ? 1 : -1;

    // Utiliser une boucle for pour itérer à travers les cases sur la diagonale
    for (int x = m_posX + stepX, y = m_posY + stepY;
        x != moveCaseX && y != moveCaseY;
        x += stepX, y += stepY) {
        if (board->m_TabPiece[y * 8 + x] != nullptr) {
            return 0; // Mouvement invalide
        }
    }

    // Vérifier si la case de destination est occupée par une pièce de la même équipe
    Piece* destinationPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
    if (destinationPiece != nullptr && destinationPiece->m_team == m_team) {
        return 0; // Mouvement invalide
    }

    return 1; // Mouvement valide
}

Bishop::~Bishop() {}
