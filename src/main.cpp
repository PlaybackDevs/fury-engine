/*			                   		*\

This file is part of Fury version 0.4-internal-dx11.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: main.cpp
==================================
File Details: The program's entry point. Try not to define globals here, or use graphics functions besides init.

Original creator: createjump


\*								*/




#include <iostream>
#include <stdio.h>
#include "util.h"




// use std namespace, great for std::vectors l8r
using namespace std;

// Use the FuryEng namespace
using namespace FuryEng;


void OpenConsole() {
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#ifdef _DEBUG
	OpenConsole();
#endif
Win32Window w1(hInstance);
if (!w1.InitializeWindow("Fury Engine")) { return -1; }
w1.Run();
FuryEng::init();
}


