#pragma once
#ifdef _WINDOW

#define NOMINMAX

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include "resource.h"

#endif

#include <iostream>
#include <cstdio>


enum ColorCustom
{
	White,
	Black
};

#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"

using namespace std;

#ifdef _WINDOW
using namespace sf;
#endif // 


#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif