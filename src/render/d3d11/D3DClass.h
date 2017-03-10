#pragma once
#include "../../util.h"
class D3DClass
{
public:
	D3DClass();
	virtual ~D3DClass();
private:
	int m_vidmem;
	char* m_vid_card[128]; // should i try a std::string? 
};

