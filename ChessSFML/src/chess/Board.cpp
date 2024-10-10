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



/*#include "Board.h"
#include "Piece.h"
#include"Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

#ifdef _LITE
void Board::InitBoard() {
    for (int i = 0; i < 64; i++) {
        m_TabPiece[i] = nullptr; // Initialisation correcte
    }

    m_TabPiece[0] = new Pawn(); // Exemple de position initiale
    m_TabPiece[0]->InitPiece(0, 0, 'P', 1, 'w'); // Exemple de Rook
    m_TabPiece[1] = new Pawn();
    m_TabPiece[1]->InitPiece(1, 1, 'P', 1, 'w'); // Exemple de Pawn
    // Initialisez les autres pièces selon votre logique
}
#endif 


#ifndef _LITE
void Board::InitBoard() {

    // Vider le tableau
    for (int i = 0; i < 64; i++) {
        m_TabPiece[i] = nullptr;
    }

    //pion blanc
    m_TabPiece[0] = new Rook();  
    m_TabPiece[0]->InitPiece(0, 0, 'R', 1, 'w');

    m_TabPiece[1] = new Knight();
    m_TabPiece[1]->InitPiece(0, 1, 'N', 1, 'w');

    m_TabPiece[2] = new Bishop();
    m_TabPiece[2]->InitPiece(0, 2, 'B', 1, 'w');

    m_TabPiece[3] = new Queen();
    m_TabPiece[3]->InitPiece(0, 3, 'Q', 1, 'w');

    m_TabPiece[4] = new King();
    m_TabPiece[4]->InitPiece(0, 4, 'K', 1, 'w');

    m_TabPiece[5] = new Bishop();
    m_TabPiece[5]->InitPiece(0, 5, 'B', 1, 'w');

    m_TabPiece[6] = new Knight();
    m_TabPiece[6]->InitPiece(0, 6, 'N', 1, 'w');

    m_TabPiece[7] = new Rook();
    m_TabPiece[7]->InitPiece(0, 7, 'R', 1, 'w');

    for (int i = 0; i < 8; i++) {
        m_TabPiece[8 + i] = new Pawn();  
        m_TabPiece[8 + i]->InitPiece(1, i, 'P', 1, 'w'); 
    }

    //pion noir 
    m_TabPiece[56] = new Rook();
    m_TabPiece[56]->InitPiece(7, 0, 'r', 1, 'b');

    m_TabPiece[57] = new Knight();
    m_TabPiece[57]->InitPiece(7, 1, 'n', 1, 'b');

    m_TabPiece[58] = new Bishop();
    m_TabPiece[58]->InitPiece(7, 2, 'b', 1, 'b');

    m_TabPiece[59] = new Queen();
    m_TabPiece[59]->InitPiece(7, 3, 'q', 1, 'b');

    m_TabPiece[60] = new King();
    m_TabPiece[60]->InitPiece(7, 4, 'k', 1, 'b');

    m_TabPiece[61] = new Bishop();
    m_TabPiece[61]->InitPiece(7, 5, 'b', 1, 'b');

    m_TabPiece[62] = new Knight();
    m_TabPiece[62]->InitPiece(7, 6, 'n', 1, 'b');

    m_TabPiece[63] = new Rook();
    m_TabPiece[63]->InitPiece(7, 7, 'r', 1, 'b');

    for (int i = 0; i < 8; i++) {
        m_TabPiece[48 + i] = new Pawn(); 
        m_TabPiece[48 + i]->InitPiece(6, i, 'p', 1, 'b');  
    }
}
#endif  



Board::Board(){
	InitBoard();
}


void Board::BoardPrint() {
    std::cout << "    A  B  C  D  E  F  G  H" << std::endl;
    std::cout << "  +------------------------+" << std::endl;

    for (int row = 0; row < 8; row++) {
        std::cout << row + 1 << " |"; // Numéro de ligne en haut

        for (int col = 0; col < 8; col++) {
            int index = row * 8 + col;

            if (m_TabPiece[index] == nullptr) {
                std::cout << " _ "; // Case vide
            }
            else {
                std::cout << " " << m_TabPiece[index]->m_symbole << " "; // Pièce
            }
        }

        std::cout << "|" << std::endl; // Fermeture de la ligne de l'échiquier
        std::cout << "  +------------------------+" << std::endl; // Bordure inférieure
    }

    std::cout << "    A  B  C  D  E  F  G  H" << std::endl;
}




Board:: ~Board(){}*/