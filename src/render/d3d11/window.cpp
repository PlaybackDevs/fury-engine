/*			                   		*\

This file is part of Fury version 0.4-internal-dx11.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: window.cpp
==================================
File Details: Win32 window class

Original creator: createjump


\*								*/


// Developer console
#include "../../util.h"
#include "../../devcons.h"
#include "window.h"

#include <Windows.h>


Win32Window::Win32Window(HINSTANCE instance)
{
	hwnd = 0;
	hInstance = instance;
    className = "FuryEngineD3D11";
}

bool Win32Window::InitializeWindow(LPCSTR windowtitle) {

	WNDCLASSEX wcex;		

	FuryEng::Logger::Log("Window class, WNDCLASSEX init", "Win32Window", __FILE__, __LINE__);
							//Set Class
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wcex.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = className;
	wcex.lpszMenuName = NULL;                       
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wcex)) { return false; 
	}

	//Create Window
	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW , className, windowtitle, WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT,
		640, 480,
		NULL, NULL, hInstance, 0);

	if (!hwnd) { 
		
		return false; 
	
	}


	//Show Window and Update Window
	FuryEng::Logger::Log("YAY!!!", "Win32Window", __FILE__, __LINE__);
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	return true;
}

LRESULT CALLBACK Win32Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		// Nothing bad "happened", so close cleanly
		FuryEng::Destruct();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

WPARAM Win32Window::Run() {
	while (GetMessage(&msg, hwnd, 0, 0) != 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}



Win32Window::~Win32Window(void){
}


