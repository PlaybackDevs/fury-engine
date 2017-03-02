/*			                   		*\

This file is part of Fury version 0.4-internal-dx11.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/

#include <Windows.h>

class Win32Window
{
public:
	Win32Window(HINSTANCE);
	~Win32Window(void);
	bool Win32Window::InitializeWindow();									
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//Message Processing
	WPARAM Run();													//Windows Application Loop

public:
	HINSTANCE hInstance;
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wcex;
	LPCSTR  className;
	RECT rc;
};

