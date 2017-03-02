/*			                   		*\

This file is part of Fury version 0.4-internal-dx11.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: main.cpp
==================================
File Details: The program's entry point. Try not to define globals here.

Original creator: createjump

\*								*/


#include <iostream>
#include <stdio.h>
#include "util.h"
#pragma region "Using Namespaces"
// use std namespace, great for std::vectors l8r
using namespace std;


// Use the FuryEng namespace
using namespace FuryEng;
#pragma endregion

void OpenConsole() {
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

}
LPCSTR Fury_Window_Title;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
// don't look in here, it contains window string stuffs
#pragma region "Please don't kill me for this"
#ifdef _DEBUG
	OpenConsole();
#ifdef _AMD64
	window = "Fury Engine (Debug, AMD64)";
#endif
#ifdef _ExxEightySix
	window = "Fury Engine (Debug, x86)";
#endif
#endif
#ifdef _RELEASE
	Fury_Window_Title = "Fury Engine";
#ifdef _AMD64
	Fury_Window_Title = "Fury Engine (AMD64)";
#endif
#ifdef _ExxEightySix
	window = "Fury Engine (x86)";
#endif
#endif
#pragma endregion
Win32Window FuryRenderer_Win32Wnd(hInstance);

if (!FuryRenderer_Win32Wnd.InitializeWindow(Fury_Window_Title)) { return -1; }

FuryEng::init();

FuryRenderer_Win32Wnd.Run();

}


