#include "pch.h"
#include "Draw.h"

//void Draw::DrawBoard(Piece** board, RenderWindow* render)
//{
//
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    render->clear();
//    render->draw(shape);
//    return;
//
//    system("cls");
//    cout << "\n" << "     A   B   C   D   E   F   G   H";
//
//    for (int y = 0; y < 8; y++)
//    {
//        cout << "\n" << "\033[90m" << "   +---+---+---+---+---+---+---+---+" << "\n" << "\033[37m" << " " << y+1 << " "; // Print a newline to separate rows
//        for (int row = 0; row < 8; x++)
//        {
//            int index = col * 8 + col;
//            cout << "\033[40m\033[90m|";
//
//            if ((x - y + 10) % 2 != 1)
//            {
//                cout << "\033[41m";
//            }
//
//            // Access the piece at (x, y)
//            Piece* piece = board[index];
//
//            if (piece == nullptr)
//            {
//                cout << "   ";
//            }else if (piece->color == White)
//            {
//                cout << "\033[37m";
//            }
//            else if (piece->color == Black)
//            {
//                cout << "\033[34m";
//            }
//
//            // Print the icon if the piece exists, or print a space if it's null
//            if (piece != nullptr) {
//                char icon = piece->icon;
//                cout << " " << icon << " ";
//            }
//        }
//        cout << "\033[40m\033[90m|";
//    }
//    cout << "\033[90m" << "\n   +---+---+---+---+---+---+---+---+";
//    cout << "\n"; // Final newline at the end
//    Reset();
//}
//
void Draw::DrawBoardPossibleMove(Piece** board, list<int> possibleMove)
{
    system("cls");
    cout << "\n" << "     A   B   C   D   E   F   G   H";

    for (int col = 0; col < 8; col++)
    {
        cout << "\n" << "\033[90m" << "   +---+---+---+---+---+---+---+---+" << "\n" << "\033[37m" << " " << col + 1 << " "; // Print a newline to separate rows
        for (int row = 0; row < 8; row++)
        {
            int index = col * 8 + row;
            cout << "\033[40m\033[90m|";

            if ((row - col + 10) % 2 != 1)
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

#ifdef _WINDOW
void Draw::DrawBoard(Piece** board, RenderWindow* render, int indexChoice, list<int> possibleMove) {

    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    render->clear();
    render->draw(shape);*/

    /*RectangleShape rectangle(Vector2f(800, 800));
    rectangle.setPosition(Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::Transparent);

    rectangle.setOutlineThickness(25);
    rectangle.setOutlineColor(sf::Color(48, 46, 43));

    render->draw(rectangle);*/


    for (int col = 0; col < 8; col++)
    {
        for (int row = 0; row < 8; row++)
        {
            int index = col * 8 + row;
            Piece* piece = board[index];

            int posX = initX + (row * 100);
            int posY = initY + (col * 100);

            RectangleShape rectangle(Vector2f(100, 100));
            rectangle.setPosition(Vector2f(posX, posY));

            if ((row - col + 10) % 2 != 1)
            {
                rectangle.setFillColor(sf::Color(235, 236, 208));
            }
            else {
                rectangle.setFillColor(sf::Color(119, 149, 86));
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
#endif // _WINDOW



void Draw::Reset()
{
    cout << "\033[37m";
    cout << "\033[40m";
}