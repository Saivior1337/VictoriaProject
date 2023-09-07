#pragma once
#include "Headers.h"

class console 
{
public:
	void setupConsole();
	void TerminateConsole();
	void printColoredText(const char* msg, WORD color);
	void clear_console_screen();
	void error_message(int errorCode, const char* msg);
};

extern console * con;