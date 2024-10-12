#include "pch.h"
#include "main.h"

#ifndef _CONSOLE 

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

Game game;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"WinAppClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	if (RegisterClassExW(&wcex) == 0)
		return 0;

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	HWND hWnd = CreateWindowW(L"WinAppClass", L"Title", WS_OVERLAPPEDWINDOW,
		0, 0, screenWidth, screenHeight, nullptr, nullptr, hInstance, nullptr);
	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//Antianialising
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Initialize SFML RenderWindow with the HWND from the created Win32 window
	sf::RenderWindow renderWindow(hWnd, settings);

	game = Game();
	game.Init(&renderWindow);

	MSG msg;
	while (renderWindow.isOpen()) {
		renderWindow.clear(Color(48, 46, 43));

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		game.GameLoop();

		//renderWindow.draw(shape);
		renderWindow.display();
	}


#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int id = LOWORD(wParam);
		int notif = HIWORD(wParam);
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:  // Left mouse button pressed
	{
		// Extract the mouse position from lParam
		int xPos = LOWORD(lParam);  // Low-order word is the x position
		int yPos = HIWORD(lParam);  // High-order word is the y position

		// Call game.GameLoop() with mouse position
		game.ConvertPosition(xPos, yPos);
		break;
	}
	case WM_RBUTTONDOWN:  // Right mouse button pressed (if needed)
	{
		int xPos = LOWORD(lParam);  // Low-order word is the x position
		int yPos = HIWORD(lParam);  // High-order word is the y position

		// Call game.GameLoop() or another method with mouse position
		game.ConvertPosition(xPos, yPos);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	}
	return 0;
}

#endif // !CONSOLE

#ifdef _CONSOLE 

int main()
{
	Game game = Game();
	game.Init();
	game.GameLoop();
}

#endif // CONSOLE