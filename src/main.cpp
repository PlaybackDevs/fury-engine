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

LPCSTR g_wndTitle;

// Direct3D globals
D3D_DRIVER_TYPE         m_type = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL       m_feature = D3D_FEATURE_LEVEL_11_0;
ID3D11Device*           m_pd3dDevice = nullptr;
ID3D11DeviceContext*    m_Context = nullptr;
IDXGISwapChain*         m_SwapChain = nullptr;
ID3D11RenderTargetView* m_RenderTargetView = nullptr;

// Direct3D class
D3DClass d3d1;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
// don't look in here, it contains window string stuffs
#pragma region "Please don't kill me for this"
#ifdef _DEBUG
	OpenConsole();
#ifdef _AMD64
	g_wndTitle = "Fury Engine (Debug, AMD64)";
#endif
#ifdef _ExxEightySix
	g_wndTitle = "Fury Engine (Debug, x86)";
#endif
#endif
#ifdef _RELEASE
	g_wndTitle = "Fury Engine";
#ifdef _AMD64
	g_wndTitle = "Fury Engine (AMD64)";
#endif
#ifdef _ExxEightySix
	g_wndTitle = "Fury Engine (x86)";
#endif
#endif
#pragma endregion
Win32Window FuryRenderer_Win32Wnd(hInstance);

if (!FuryRenderer_Win32Wnd.InitializeWindow(g_wndTitle)) { return -1; }
FuryEng::init();
d3d1.D3DInit(FuryRenderer_Win32Wnd.hwnd, m_pd3dDevice, m_type, m_feature, m_Context, m_SwapChain, m_RenderTargetView);
FuryRenderer_Win32Wnd.Run();

}


