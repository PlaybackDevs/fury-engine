/*			                   		*\

This file is part of Fury version 0.4-internal-dx10.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: util.cpp
==================================
File Details: The Utility section of the Fury engine.

Original creator: createjump


\*								*/

#include <Windows.h>
#include <iostream>
#include "util.h"



namespace FuryEng
{
void init(){
// This is the init function, which initalizes all of Playback's game code (ie audio, DX10, Input).
FuryEng::Logger::Log("Initializing FuryEngine game code", "INIT", __FILE__, __LINE__);
FuryEng::Logger::Log("FuryEngine Startup complete", "INIT" , __FILE__, __LINE__ );

}

void Destruct(){
	FuryEng::Logger::Log("FuryEngine exiting...", "INIT", __FILE__, __LINE__);
	exit(0);
}

}
