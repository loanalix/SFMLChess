#include "pch.h"
#include "Bishop.h"

void Bishop::Init(ColorCustom c, int x, int y)
{
    icon = 'B';

    color = c;

    posX = x;
    posY = y;

    string path = "";

    if (color == White)
    {
        path = "..\\..\\..\\src\\p2\\wb.png";
    }
    else {
        path = "..\\..\\..\\src\\p2\\bb.png";
    }

    if (!texture.loadFromFile(path))
    {
        cout << "n";
        // erreur...
    }
}

bool Bishop::Move(Piece* board[64], int pos1) {
    int y = pos1 / 8;
    int x = pos1 % 8;
    int index = posY * 8 + posX;
    int diffX = x - posX;
    int diffY = y - posY;
    int diffXAbs = abs(diffX);
    int diffYAbs = abs(diffY);

    if (diffXAbs == diffYAbs)
    {
        for (int i = 1; i < diffXAbs; i++)
        {
            int indexCaseX = posX + (i * (diffX / diffXAbs));
            int indexCaseY = posY + (i * (diffY / diffYAbs));

            if (board[indexCaseY * 8 + indexCaseX] != nullptr)
            {
                return false;
            }
        }
        board[pos1] = board[index];
        board[index] = nullptr;

        posY = y;
        posX = x;

        return true;
    }

    return false;
}

std::list<int> Bishop::GetPossibleMoves(Piece* board[64], int pos1)
{
    std::list<int> possibleMoves;

    int y = pos1 / 8;  // Row (y-axis)
    int x = pos1 % 8;  // Column (x-axis)

    // Check top-left diagonal (y decreases, x decreases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 - i * 9;  // Moving diagonally top-left
        if (newPos < 0 || newPos % 8 == 7) break;  // Out of bounds (left edge)

        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Capture the opponent and stop further movement
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check top-right diagonal (y decreases, x increases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 - i * 7;  // Moving diagonally top-right
        if (newPos < 0 || newPos % 8 == 0) break;  // Out of bounds (right edge)

        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Capture the opponent and stop further movement
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check bottom-left diagonal (y increases, x decreases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 + i * 7;  // Moving diagonally bottom-left
        if (newPos >= 64 || newPos % 8 == 7) break;  // Out of bounds (left edge)

        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Capture the opponent and stop further movement
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    // Check bottom-right diagonal (y increases, x increases)
    for (int i = 1; i < 8; ++i)
    {
        int newPos = pos1 + i * 9;  // Moving diagonally bottom-right
        if (newPos >= 64 || newPos % 8 == 0) break;  // Out of bounds (right edge)

        if (board[newPos] == nullptr)  // Empty square
        {
            possibleMoves.push_back(newPos);
        }
        else if (board[newPos]->color != this->color)  // Opponent's piece
        {
            possibleMoves.push_back(newPos);
            break;  // Capture the opponent and stop further movement
        }
        else  // Own piece
        {
            break;  // Blocked by own piece
        }
    }

    return possibleMoves;
}
