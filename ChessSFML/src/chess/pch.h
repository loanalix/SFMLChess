#pragma once

#define NOMINMAX

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <cstdio>
#include <windows.h>

#include "resource.h"

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
using namespace sf;

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif