#include "pch.h"
#include "Game.h"
#include "Board.h"
#include "Piece.h"

#ifdef _DEMO
#define MAX_TURN 2 
#endif 

#ifndef _DEMO
#define MAX_TURN -1
#endif


Game::Game() {}


void Game::InitGame()
{
    board = new Board();
    board->InitBoard();
    m_turn = 'w';
    error = "";
    m_nubTurn = 0;
}

void Game::GameLoop()
{
    while (true)
    {
        char pieceToMove[3];
        char pieceDestination[3];

        board->BoardPrint();

        std::cout << error << std::endl;
        error = "";

        if (m_nubTurn == MAX_TURN) {
            std::cout << "Merci d'avoir jouer à la demo, acheter pour plus" << std::endl;
            return;
        }


        std::cout << "Piece to move (ex A5, H2) : " << std::endl;
        std::cin >> pieceToMove;
        std::cout << "Piece destination (ex A5, H2) : " << std::endl;
        std::cin >> pieceDestination;

        int originX, originY, destX, destY;
        ConvertInput(pieceToMove, &originX, &originY);
        ConvertInput(pieceDestination, &destX, &destY);

        PostMessage("Le pion a bouger");

        if (board->m_TabPiece[originY * 8 + originX] == nullptr)
        {
            error = "Erreur, case vide !";
            continue;
        }

        if (board->m_TabPiece[originY * 8 + originX]->m_team != m_turn)
        {
            error = "Erreur, cette piece n'est pas a vous !";
            continue;

        }

        if (!board->m_TabPiece[originY * 8 + originX]->Move(destX, destY, board))
        {
            error = "Erreur, mouvement impossible";
            continue;
        }

        ChangeTurn();


    }
}

bool Game::ConvertInput(const char* input, int* posX, int* posY)
{
    char letter = input[0];
    char number = input[1];
    if (letter < 'A' || letter > 'H' || number < '1' || number > '8') return false;

    *posX = letter - 'A';
    *posY = number - '1';

    return true;
}

void Game::ChangeTurn()
{
    if (m_turn == 'w')
    {
        std::cout << "b " << m_nubTurn << std::endl;
        m_turn = 'b';
    }
    else
        std::cout << "w " << m_nubTurn << std::endl;
    m_turn = 'w';
    m_nubTurn++;
}

Game::~Game() {}