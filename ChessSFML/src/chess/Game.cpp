#include "pch.h"
#include "Game.h"

#ifdef _DEMO
#define TOTALMOVE 3
#endif // _LIGHT

#ifndef _DEMO
#define TOTALMOVE -1
#endif // !_DEMO


void Game::Init(RenderWindow* r)
{
	render = r;
	move = TOTALMOVE;
	board = Board();
	board.Init();
}




void Game::GameLoop()
{
	if (!isGame)
	{
		return;
	}
	Draw draw = Draw();

	if (index1 != -1)
	{
		if (board.board[index1] == nullptr || player != board.board[index1]->color)
		{
			index1 = -1;
		}
		else if (possibleMove.size() == 0)
		{
			possibleMove = board.board[index1]->GetPossibleMoves(board.board, index1);
			if (possibleMove.size() == 0)
			{
				index1 = -1;
			}
		}
	}

	if (index2 != -1)
	{
		bool isKing = false;

		if (board.board[index2] != nullptr)
		{
			if (board.board[index2]->icon == 'K')
			{
				isKing = true;
			}
		}

		if (board.board[index1] == nullptr || index1 == index2)
		{
			index1 = -1;
			index2 = -1;
		}
		else if (board.board[index2] != nullptr && board.board[index1]->color == board.board[index2]->color)
		{

		}
		else if (player == board.board[index1]->color)
		{
			bool isPass;

			bool found = (find(possibleMove.begin(), possibleMove.end(), index2) != possibleMove.end());

			if (found)
			{
				if (board.board[index1]->icon == 'P')
				{
					Pawn* p = (Pawn*)board.board[index1];
					p->SpecialMove(board.board, index2);
				}
				//board.board[index1]->Move(board.board, index2);
				board.board[index2] = board.board[index1];
				board.board[index1] = nullptr;
				board.board[index2]->posX = index2 % 8;
				board.board[index2]->posY = index2 / 8;
			}

			//isPass = board.board[index1]->Move(board.board, index2);

			if (found)
			{
				if (isKing)
				{
					isGame = false;
				}

				if (player == White)
				{
					player = Black;
				}
				else {
					player = White;
				}
			}
		}
		possibleMove.clear();

		index1 = -1;
		index2 = -1;
	}

	draw.DrawBoard(board.board, render, index1, possibleMove);
	return;



	while (isGame)
	{
		Draw draw = Draw();

		//draw.DrawBoard(board.board);

		char pieceToMove[2];
		char caseToMove[2];

		if (player == White)
		{
			cout << "White: ";
		}
		else {
			cout << "Black: ";
		}

		cout << "un truc: ";
		cin >> pieceToMove;

		int pos1 = ConvertToPosition(pieceToMove);


		//Verif if can play

		//If out of range
		if (pos1 > 64 || pos1 < 0)
		{
			continue;
		}
		//if not select a piece
		if (board.board[pos1] == nullptr)
		{
			continue;
		}

		list<int> possibleMove = list<int>();

		if (board.board[pos1]->color == player)
		{
			possibleMove = board.board[pos1]->GetPossibleMoves(board.board, pos1);
			draw.DrawBoardPossibleMove(board.board, possibleMove);
		}
		else { continue; }

		cin >> caseToMove;

		int pos2 = ConvertToPosition(caseToMove);

		if (pos2 > 64 || pos2 < 0)
		{
			continue;
		}

		//if you try to kill yourself
		if (board.board[pos2] != nullptr)
		{
			if (board.board[pos1]->color == board.board[pos2]->color)
			{
				continue;
			}
		}

		//if you play on the same place
		if (pos1 == pos2)
		{
			continue;
		}

		bool isKing = false;
		bool isPossible = true;

		if (board.board[pos2] != nullptr)
		{
			if (board.board[pos2]->icon == 'K')
			{
				isKing = true;
			}
		}

		if (board.board[pos1]->color == player)
		{
			isPossible = board.board[pos1]->Move(board.board, pos2);
		}
		else { continue; }

		if (!isPossible)
		{
			continue;
		}

		if (isKing)
		{
			isGame = false;
			if (player == White)
			{
				cout << "Victoire des Blancs";
			}
			else {
				cout << "Victoire des Noirs";
			}
		}

		if (player == White)
		{
			move--;
		}

		if (move == 0)
		{
			isGame = false;
			cout << "\nFin de la demo \n";
		}

		if (player == White)
		{
			player = Black;
		}
		else {
			player = White;
		}
	}
}

int Game::ConvertToPosition(char text[2]) {

	char column = text[0];
	char row = text[1];

	if (column < 'A' || column > 'H' || row < '1' || row > '8')
		return -1;

	int colIndex = column - 'A';
	int rowIndex = row - '1';

	return rowIndex * 8 + colIndex;
}

void Game::MakeMove(int x, int y) {
	// Define the top-left corner of the board (50, 50) and the size of each case (100x100 pixels)
	const int boardStartX = 50;
	const int boardStartY = 50;
	const int caseSize = 100;

	// Calculate the column and row based on the mouse position
	int column = (x - boardStartX) / caseSize; // (x - 50) / 100
	int row = (y - boardStartY) / caseSize;    // (y - 50) / 100

	// Make sure the mouse click is inside the board (0 <= row, column < 8)
	if (column >= 0 && column < 8 && row >= 0 && row < 8) {
		// Calculate the index of the clicked case (board is 8x8, index = y * 8 + x)
		int index = row * 8 + column;
		if (index1 == -1)
		{
			index1 = index;
		}
		else
		{
			index2 = index;
		}
	}
}