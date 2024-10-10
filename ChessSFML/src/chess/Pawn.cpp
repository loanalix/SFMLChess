#include"pch.h"
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn() {}



void Pawn::InitPiece(int posX, int posY, char symbole, int sense, char team)
{

    Piece::InitPiece(posX, posY, symbole, sense, team);

    firstTurn = true;

}

int Pawn::CheckMove(int moveCaseX, int moveCaseY, Board* board)
{
    int direction = (m_team == 'w') ? 1 : -1;
    int startRow = (m_team == 'w') ? 1 : 6;

    // Premier mouvement de 2 cases
    if (firstTurn && moveCaseY == m_posY + 2 * direction && m_posX == moveCaseX) {
        if (board->m_TabPiece[m_posY + direction * 1 * 8 + m_posX] == nullptr &&
            board->m_TabPiece[m_posY + direction * 2 * 8 + m_posX] == nullptr) {
            firstTurn = false;
            return 1; // Mouvement valide
        }
        return 0; // Mouvement invalide
    }

    // Mouvement normal de 1 case
    if (moveCaseY == m_posY + direction && m_posX == moveCaseX) {
        if (board->m_TabPiece[moveCaseY * 8 + moveCaseX] == nullptr) {
            firstTurn = false;
            return 1; // Mouvement valide
        }
        return 0; // Mouvement invalide
    }

    // Capture en diagonale
    if (moveCaseY == m_posY + direction && (moveCaseX == m_posX + 1 || moveCaseX == m_posX - 1)) {
        // Vérifier si la case contient une pièce ennemie
        Piece* targetPiece = board->m_TabPiece[moveCaseY * 8 + moveCaseX];
        if (targetPiece != nullptr && targetPiece->m_team != m_team) {
            firstTurn = false;
            return 1; // Mouvement valide
        }
        return 0; // Mouvement invalide
    }

    return 0; // Aucune autre condition remplie
}



Pawn::~Pawn() {}
