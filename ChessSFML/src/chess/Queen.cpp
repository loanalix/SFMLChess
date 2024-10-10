#include"pch.h"
#include "Queen.h"

Queen::Queen() {}

int Queen::HorizontaVerticallMove(int moveCaseX, int moveCaseY, Board* board) {
    int incrementX = (moveCaseX > m_posX) ? 1 : (moveCaseX < m_posX) ? -1 : 0; // Direction horizontale
    int incrementY = (moveCaseY > m_posY) ? 1 : (moveCaseY < m_posY) ? -1 : 0; // Direction verticale

    // Vérification horizontale
    if (incrementX != 0) {
        for (int i = m_posX + incrementX; i != moveCaseX; i += incrementX) {
            if (board->m_TabPiece[m_posY * 8 + i] != nullptr) {
                return 0; // Mouvement invalide
            }
        }
    }
    // Vérification verticale
    else if (incrementY != 0) {
        for (int j = m_posY + incrementY; j != moveCaseY; j += incrementY) {
            if (board->m_TabPiece[j * 8 + m_posX] != nullptr) {
                return 0; // Mouvement invalide
            }
        }
    }

    // Vérifier si la case de destination est occupée par une pièce de la même équipe
    Piece* destinationPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
    if (destinationPiece != nullptr && destinationPiece->m_team == m_team) {
        return 0; // Mouvement invalide
    }

    return 1; // Mouvement valide
}

int Queen::DiagonalMove(int moveCaseX, int moveCaseY, Board* board) {
    int deltaX = moveCaseX - m_posX;
    int deltaY = moveCaseY - m_posY;

    if (abs(deltaX) != abs(deltaY) || (deltaX == 0 && deltaY == 0)) {
        return 0; // Mouvement invalide
    }

    int stepX = (deltaX > 0) ? 1 : -1;
    int stepY = (deltaY > 0) ? 1 : -1;

    // Utiliser une boucle for pour itérer à travers les cases sur la diagonale
    for (int x = m_posX + stepX, y = m_posY + stepY; x != moveCaseX && y != moveCaseY; x += stepX, y += stepY) {
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

int Queen::CheckMove(int moveCaseX, int moveCaseY, Board* board) {
    // Vérification pour les mouvements horizontaux/verticaux
    if (moveCaseX == m_posX || moveCaseY == m_posY) {
        return HorizontaVerticallMove(moveCaseX, moveCaseY, board);
    }
    // Vérification pour les mouvements diagonaux
    else if (abs(moveCaseX - m_posX) == abs(moveCaseY - m_posY)) {
        return DiagonalMove(moveCaseX, moveCaseY, board);
    }

    return 0; // Mouvement invalide
}

Queen::~Queen() {}