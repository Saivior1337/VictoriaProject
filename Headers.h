#pragma once
#include <iostream>
#include <winsock2.h> 
#include <TlHelp32.h>
#include <string>
#include <tchar.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include "psapi.h"
#include <intrin.h>
#include "urlmon.h"
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <ws2tcpip.h>
#include "winternl.h"
#include "resource.h"

#include "xorstr.h"
#include "console.h"
#include "ProcessMemory.h"
#include "GlobalVars.h"
#include "steam_api.h"
#include "OffsetManager.h"
#include "SteamAPI.h"
#include "Utils.h"
#include "server.h"
#include "json.h"
#include "httplib.h"
#include "CEntity.h"
#include "Misc.h"
#include "Visuals.h"
#include "Models.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")

using namespace std::chrono_literals;
using namespace httplib;
using json = nlohmann::json;

