#include"pch.h"
#include "Rook.h"
#include "Board.h"

Rook::Rook() {}

int Rook::CheckMove(int moveCaseX, int moveCaseY, Board* board) {

    int incrementX = (moveCaseX > m_posX) ? 1 : (moveCaseX < m_posX) ? -1 : 0; // Direction horizontale
    int incrementY = (moveCaseY > m_posY) ? 1 : (moveCaseY < m_posY) ? -1 : 0; // Direction verticale

    // V�rification du mouvement horizontal
    if (incrementX != 0) {
        for (int i = m_posX + incrementX; i != moveCaseX; i += incrementX) {
            if (board->m_TabPiece[m_posY * 8 + i] != nullptr) {
                return 0; // Mouvement invalide, case occup�e
            }
        }
    }
    // V�rification du mouvement vertical
    else if (incrementY != 0) {
        for (int j = m_posY + incrementY; j != moveCaseY; j += incrementY) {
            if (board->m_TabPiece[j * 8 + m_posX] != nullptr) {
                return 0; // Mouvement invalide, case occup�e
            }
        }
    }

    // V�rifier si la case de destination est occup�e par une pi�ce de la m�me �quipe
    Piece* destinationPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
    if (destinationPiece != nullptr && destinationPiece->m_team == m_team) {
        return 0; // Mouvement invalide, pi�ce de la m�me �quipe
    }

    return 1; // Mouvement valide
}

Rook::~Rook() {}