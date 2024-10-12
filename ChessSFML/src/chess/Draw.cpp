#include "pch.h"
#include "Draw.h"

#ifdef _CONSOLE

void Draw::DrawBoard(Piece** board, int indexChoice, list<int> possibleMove)
{
    system("cls");
    cout << "\n" << "     A   B   C   D   E   F   G   H";

    for (int y = 0; y < 8; y++)
    {
        cout << "\n" << "\033[90m" << "   +---+---+---+---+---+---+---+---+" << "\n" << "\033[37m" << " " << y + 1 << " "; // Print a newline to separate rows
        for (int x = 0; x < 8; x++)
        {
            int index = y * 8 + x;
            cout << "\033[40m\033[90m|";

            if ((x - y + 10) % 2 != 1)
            {
                cout << "\033[41m";
            }

            // Access the piece at (x, y)
            Piece* piece = board[index];

            if (piece == nullptr)
            {
                cout << "   ";
            }
            else if (piece->color == White)
            {
                cout << "\033[37m";
            }
            else if (piece->color == Black)
            {
                cout << "\033[34m";
            }

            // Print the icon if the piece exists, or print a space if it's null
            if (piece != nullptr) {
                char icon = piece->icon;
                cout << " " << icon << " ";
            }
        }
        cout << "\033[40m\033[90m|";
    }
    cout << "\033[90m" << "\n   +---+---+---+---+---+---+---+---+";
    cout << "\n"; // Final newline at the end
    Reset();
}

#endif // _CONSOLE

#ifndef _CONSOLE

void Draw::DrawBoard(Piece** board, RenderWindow* render, int indexChoice, list<int> possibleMove) {
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            int index = y * 8 + x;
            Piece* piece = board[index];

            int posX = initX + (x * 100);
            int posY = initY + (y * 100);

            RectangleShape rectangle(Vector2f(100, 100));
            rectangle.setPosition(Vector2f(posX, posY));

            if ((x - y + 10) % 2 != 1)
            {
                rectangle.setFillColor(ColorWhite);
            }
            else {
                rectangle.setFillColor(ColorBlack);
            }

            render->draw(rectangle);

            if (index == indexChoice)
            {
                CircleShape circle(45);
                circle.setPosition(Vector2f(posX + 5, posY + 5));
                circle.setFillColor(sf::Color(111, 255, 145, 127));
                render->draw(circle);
            }

            bool found = (find(possibleMove.begin(), possibleMove.end(), index) != possibleMove.end());

            if (found)
            {
                if (board[index] != nullptr)
                {
                    CircleShape circle(40);
                    circle.setPosition(Vector2f(posX + 10, posY + 10));
                    circle.setFillColor(sf::Color(252, 36, 3, 50));
                    render->draw(circle);
                }
                else {
                    CircleShape circle(20);
                    circle.setPosition(Vector2f(posX + 30, posY + 30));
                    circle.setFillColor(sf::Color(0, 0, 0, 50));
                    render->draw(circle);
                }
            }

            if (piece == nullptr)
            {
                continue;
            }

            Sprite sprite;
            //sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));
            sprite.setTexture(piece->texture);
            sprite.setPosition(Vector2f(posX, posY));

            render->draw(sprite);
        }
    }

}

#endif // !_CONSOLE


void Draw::DrawBoardPossibleMove(Piece** board, list<int> possibleMove)
{
    system("cls");
    cout << "\n" << "     A   B   C   D   E   F   G   H";

    for (int y = 0; y < 8; y++)
    {
        cout << "\n" << "\033[90m" << "   +---+---+---+---+---+---+---+---+" << "\n" << "\033[37m" << " " << y + 1 << " "; // Print a newline to separate rows
        for (int x = 0; x < 8; x++)
        {
            int index = y * 8 + x;
            cout << "\033[40m\033[90m|";

            if ((x - y + 10) % 2 != 1)
            {
                cout << "\033[41m";
            }

            // Access the piece at (x, y)
            Piece* piece = board[index];

            if (find(possibleMove.begin(), possibleMove.end(), index) != possibleMove.end())
            {
                if (board[index] == nullptr)
                {
                    cout << "\033[43m";
                }
                else
                {
                    cout << "\033[42m";
                }
            }

            if (piece == nullptr)
            {
                cout << "   ";
            }
            else if (piece->color == White)
            {
                cout << "\033[37m";
            }
            else if (piece->color == Black)
            {
                cout << "\033[34m";
            }

            // Print the icon if the piece exists, or print a space if it's null
            if (piece != nullptr) {
                char icon = piece->icon;
                cout << " " << icon << " ";
            }
        }
        cout << "\033[40m\033[90m|";
    }
    cout << "\033[90m" << "\n   +---+---+---+---+---+---+---+---+";
    cout << "\n"; // Final newline at the end
    Reset();
}


void Draw::Reset()
{
    cout << "\033[37m";
    cout << "\033[40m";
}