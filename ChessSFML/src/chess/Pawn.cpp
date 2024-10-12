#include "pch.h"
#include "Pawn.h"


void Pawn::Init(ColorCustom c, int x, int y)
{
    icon = 'P';

    color = c;

    posX = x;
    posY = y;
#ifndef _CONSOLE 
    string path = "";

    if (color == White)
    {
        path = "..\\..\\..\\src\\chess\\Texture\\white_pawn.png";
    }
    else {
        path = "..\\..\\..\\src\\chess\\Texture\\black_pawn.png";
    }

    if (!texture.loadFromFile(path))
    {
        cout << "n";
        // erreur...
    }
#endif // !_CONSOLE || _CONSOLEDEBUG
}

void Pawn::SpecialMove(Piece* board[64], int pos1)
{
    int y = pos1 / 8;
    int x = pos1 % 8;
    int index = posY * 8 + posX;

    isFirstMove = false;

    if (board[index]->color == White && y == 7 && isQueen == false)
    {
        isQueen = true;
        Queen* queen = new Queen();
        queen->Init(White, posX, posY);

        Piece* temp = board[index];

        board[index] = (Piece*)queen;
    }
    else if (board[index]->color == Black && y == 0 && isQueen == false)
    {
        isQueen = true;
        Queen* queen = new Queen();
        queen->Init(Black, posX, posY);

        Piece* temp = board[index];

        board[index] = (Piece*)queen;
    }
}

std::list<int> Pawn::GetPossibleMoves(Piece* board[64], int pos1)
{
    std::list<int> possibleMoves;

    int y = pos1 / 8;
    int x = pos1 % 8;
    int index = posY * 8 + posX;

    // Check if the pawn can move forward
    if (color == Black)
    {
        if (board[pos1 - 8] == nullptr)
        {
            possibleMoves.push_back(pos1 - 8);

            // Check if it is the pawn's first move
            if (isFirstMove && board[pos1 - 16] == nullptr)
            {
                possibleMoves.push_back(pos1 - 16);
            }
        }
    }
    else if (color == White)
    {
        if (board[pos1 + 8] == nullptr)
        {
            possibleMoves.push_back(pos1 + 8);

            // Check if it is the pawn's first move
            if (isFirstMove && board[pos1 + 16] == nullptr)
            {
                possibleMoves.push_back(pos1 + 16);
            }
        }
    }

    // Check if the pawn can capture diagonally
    if (color == Black)
    {
        if (pos1 - 7 > 0 && board[pos1 - 7] != nullptr && board[pos1 - 7]->color == White)
        {
            possibleMoves.push_back(pos1 - 7);
        }
        if (pos1 - 9 > 0 && board[pos1 - 9] != nullptr && board[pos1 - 9]->color == White)
        {
            possibleMoves.push_back(pos1 - 9);
        }
    }
    else if (color == White)
    {
        if (pos1 + 9 < 64 && board[pos1 + 9] != nullptr && board[pos1 + 9]->color == Black)
        {
            possibleMoves.push_back(pos1 + 9);
        }
        if (pos1 + 7 < 64 && board[pos1 + 7] != nullptr && board[pos1 + 7]->color == Black)
        {
            possibleMoves.push_back(pos1 + 7);
        }
    }

    return possibleMoves;
}
