#pragma once
#include "Headers.h"

class server
{
public:
	static unsigned __stdcall session(void*);
	void OpenWebMenu();
};

extern server * web;