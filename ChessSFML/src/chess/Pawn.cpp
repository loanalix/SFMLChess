#include "pch.h"
#include "Pawn.h"

#include <complex.h>

void Pawn::Init(ColorCustom c, int x, int y)
{
    icon = 'P';

    color = c;

    posX = x;
    posY = y;

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
}

bool Pawn::Move(Piece* board[64], int pos1) {
    if (isQueen)
    {
        //Queen Movement
        bool isMove;

        isMove = queen.Move(board, pos1);
        posX = queen.posX;
        posY = queen.posY;
        return isMove;
    }

    int y = pos1 / 8;
    int x = pos1 % 8;
    int diffX = x - posX;
    int xAbs = abs(x);
    int diffXAbs = abs(diffX);
    int index = posY * 8 + posX;

    if ((y == posY - 1 && diffXAbs == 1 && color == Black) || (y == posY + 1 && diffXAbs == 1 && color == White)) {
        if (board[pos1] != nullptr)
        {
            MoveCode(board, pos1);
            /*board[pos1] = board[index];
            board[index] = nullptr;

            posY = y;
            posX = x;*/

            isFirstMove = false;

            return true;
        }
        return false;
    }

    if (board[pos1] != nullptr)
    {
        return false;
    }

    if (isFirstMove)
    {
        if ((y == posY - 2 && x == posX && color == Black) || (y == posY + 2 && x == posX && color == White)) {
            if (board[pos1 + 8] == nullptr && color == Black || board[pos1 - 8] == nullptr && color == White)
            {
                MoveCode(board, pos1);
                /*board[pos1] = board[index];
                board[index] = nullptr;

                posY = y;
                posX = x;*/

                isFirstMove = false;

                return true;
            }
        }

    }

    if (y == posY - 1 && color == Black || y == posY + 1 && color == White) {

        MoveCode(board, pos1);
        /*board[pos1] = board[index];
        board[index] = nullptr;

        posY = y;
        posX = x;*/

        isFirstMove = false;

        return true;
    }

    return false;
}

void Pawn::SpecialMove(Piece* board[64], int pos1)
{
    int y = pos1 / 8;
    int x = pos1 % 8;
    int index = posY * 8 + posX;

    isFirstMove = false;

    if (board[index]->color == White && y == 7 && isQueen == false)
    {
        queen = Queen();
        queen.Init(White, posX, posY);
        isQueen = true;
        texture = queen.texture;
        icon = 'Q';
    }
    else if (board[index]->color == Black && y == 0 && isQueen == false)
    {
        queen = Queen();
        queen.Init(Black, posX, posY);
        isQueen = true;
        texture = queen.texture;
        icon = 'Q';
    }
}

//
//bool Pawn::Move(Piece* board[64], int pos1) {
//	if (isQueen)
//	{
//        //Queen Movement
//        bool isMove;
//
//        isMove = queen.Move(board, pos1);
//        posX = queen.posX;
//        posY = queen.posY;
//		return isMove;
//	}
//
//	int y = pos1 / 8;
//	int x = pos1 % 8;
//	int diffX = x - posX;
//	int xAbs = abs(x);
//	int diffXAbs = abs(diffX);
//	int index = posY * 8 + posX;
//
//	if ((y == posY - 1 && diffXAbs == 1 && color == Black) || (y == posY + 1 && diffXAbs == 1 && color == White)) {
//		if (board[pos1] != nullptr)
//		{
//			MoveCode(board, pos1);
//			/*board[pos1] = board[index];
//			board[index] = nullptr;
//
//			posY = y;
//            posX = x;*/
//
//            isFirstMove = false;
//
//			return true;
//		}
//		return false;
//	}
//
//	if (board[pos1] != nullptr)
//	{
//		return false;
//	}
//
//	if (isFirstMove)
//	{
//		if ((y == posY - 2 && x == posX && color == Black) || (y == posY + 2 && x == posX && color == White)) {
//			if (board[pos1 + 8] == nullptr && color == Black || board[pos1 - 8] == nullptr && color == White)
//			{
//                MoveCode(board, pos1);
//                /*board[pos1] = board[index];
//                board[index] = nullptr;
//
//                posY = y;
//                posX = x;*/
//
//				isFirstMove = false;
//
//				return true;
//			}
//		}
//		
//	}
//	
//	if (y == posY - 1 && color == Black || y == posY + 1 && color == White){
//
//        MoveCode(board, pos1);
//        /*board[pos1] = board[index];
//        board[index] = nullptr;
//
//        posY = y;
//        posX = x;*/
//
//        isFirstMove = false;
//
//		return true;
//	}
//
//	return false;
//}

void Pawn::MoveCode(Piece* board[64], int pos1)
{
    int y = pos1 / 8;
    int x = pos1 % 8;
    int index = posY * 8 + posX;

    if (board[index]->color == White && y == 7 && isQueen == false)
    {
        queen = Queen();
        queen.Init(White, posX, posY);
        isQueen = true;
        texture = queen.texture;
        icon = 'Q';
    }
    else if (board[index]->color == Black && y == 0 && isQueen == false)
    {
        queen = Queen();
        queen.Init(Black, posX, posY);
        isQueen = true;
        texture = queen.texture;
        icon = 'Q';
    }

    board[pos1] = board[index];
    board[index] = nullptr;

    posY = y;
    posX = x;


}

std::list<int> Pawn::GetPossibleMoves(Piece* board[64], int pos1)
{
    if (isQueen)
    {
        //Queen possible movement
        return queen.GetPossibleMoves(board, pos1);
    }

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
        if (x > 0 && board[pos1 - 7] != nullptr && board[pos1 - 7]->color == White)
        {
            possibleMoves.push_back(pos1 - 7);
        }
        if (x < 7 && board[pos1 - 9] != nullptr && board[pos1 - 9]->color == White)
        {
            possibleMoves.push_back(pos1 - 9);
        }
    }
    else if (color == White)
    {
        if (x > 0 && board[pos1 + 9] != nullptr && board[pos1 + 9]->color == Black)
        {
            possibleMoves.push_back(pos1 + 9);
        }
        if (x < 7 && board[pos1 + 7] != nullptr && board[pos1 + 7]->color == Black)
        {
            possibleMoves.push_back(pos1 + 7);
        }
    }

    return possibleMoves;
}