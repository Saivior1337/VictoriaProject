#pragma once
#include "Headers.h"

class SteamAPI
{
public:
	void OpenSteamOverlayBrowser(const char* url);
};

extern SteamAPI * api;