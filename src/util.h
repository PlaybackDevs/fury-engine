#ifndef UTIL_INCLUDED
#define UTIL_INCLUDED
/*			                   		*\

This file is part of Fury version 0.4-internal-dx11.

Copyright (c) 2017 createjump & Spectre.

\*			                   		*/



/*								*\
File: util.h
==================================
File Details: Utility section header.

Original creator: createjump


\*								*/


#include <iostream>


#include "devcons.h"

// header protection
#ifndef _WINDOW
#include "render\d3d11\window.h"
#endif
#include "render\d3d11\D3DClass.h"

namespace FuryEng{
	
void init();
void Destruct();
}



#endif // UTIL_INCLUDED
