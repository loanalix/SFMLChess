#include "pch.h"
#include "Window.h"
//
//
//void Window::InitWindow(HINSTANCE hInstance, int nCmdShow)
//{
//	WNDCLASSEXW wcex;
//	wcex.cbSize = sizeof(WNDCLASSEX);
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr;
//	wcex.lpszClassName = L"WinAppClass";
//	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	if (RegisterClassExW(&wcex) == 0)
//		return;
//
//	HWND hWnd = CreateWindowW(L"WinAppClass", L"Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	if (hWnd == NULL)
//		return ;
//
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//}
//
//
//LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam,LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_DESTROY:
//	{
//		PostQuitMessage(0);
//		break;
//	}
//	default:
//	{
//		return DefWindowProc(hWnd, message, wParam, lParam);
//		break;
//	}
//	}
//	return 0;
//}
