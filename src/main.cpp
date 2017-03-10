/*			                   		*\

This file is part of Fury version 0.5.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: main.cpp
==================================
File Details: The program's entry point.

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

/*
	@info This allows a Win32 program to use the console.

*/
void OpenConsole() {
	// This allows a Win32 app to use the console.
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

}

/*window title*/
LPCSTR Fury_Window_Title;

D3DClass d3d1;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
// don't look in here, it contains window string stuffs
#pragma region "Window defines"
#ifdef _DEBUG
	OpenConsole();
#ifdef _AMD64
	Fury_Window_Title = "Fury Engine (Debug, AMD64) Direct3D 11";
#endif
#ifdef _ExxEightySix
	Fury_Window_Title = "Fury Engine (Debug, x86) Direct3D 11";
#endif
#endif
#ifdef _RELEASE
#ifdef _AMD64
	Fury_Window_Title = "Fury Engine (AMD64) Direct3D 11";
#endif
#ifdef _ExxEightySix
	Fury_Window_Title = "Fury Engine (x86) Direct3D 11";
#endif
#endif
#pragma endregion
Win32Window FuryRenderer_Win32Wnd(hInstance);

if (!FuryRenderer_Win32Wnd.InitializeWindow(Fury_Window_Title)) { return -1; }
FuryEng::init();
FuryRenderer_Win32Wnd.Run();

}


