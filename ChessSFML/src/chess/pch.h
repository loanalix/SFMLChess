//pch.h

#pragma once

#define NOMINMAX

#include <windows.h>

#include "resource.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
#include <SFML/Graphics.hpp>
