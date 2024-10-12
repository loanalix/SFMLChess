#include "pch.h"
#include "Rook.h"

void Rook::Init(ColorCustom c, int x, int y)
{
    icon = 'R';

    color = c;

    posX = x;
    posY = y;
#ifndef _CONSOLE 
    string path = "";

    if (color == White)
    {
        path = "..\\..\\..\\src\\chess\\Texture\\white_rook.png";
    }
    else {
        path = "..\\..\\..\\src\\chess\\Texture\\black_rook.png";
    }

    if (!texture.loadFromFile(path))
    {
        cout << "n";
        // erreur...
    }
#endif // !_CONSOLE || _CONSOLEDEBUG
}

std::list<int> Rook::GetPossibleMoves(Piece* board[64], int pos1)
{
    std::list<int> possibleMoves;

    int y = pos1 / 8;  // Row (y-axis)
    int x = pos1 % 8;  // Column (x-axis)

    // Check upward movement (y decreases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 - i * 8;
        if (newPos < 0) break;  // Out of bounds
        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Stop further movement in this direction (capture)
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check downward movement (y increases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 + i * 8;
        if (newPos >= 64) break;  // Out of bounds
        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Stop further movement in this direction (capture)
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check leftward movement (x decreases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 - i;
        if (newPos % 8 == 7) break;  // Out of bounds
        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Stop further movement in this direction (capture)
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check rightward movement (x increases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 + i;
        if (newPos % 8 == 0) break;  // Out of bounds
        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Stop further movement in this direction (capture)
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    return possibleMoves;
}