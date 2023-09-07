#include "ProcessMemory.h"

ProcessMemory* mem;

HWND ProcessMemory::getGameWindow()
{
	HWND gameHWND = FindWindow(NULL, XOR("Counter-Strike: Global Offensive - Direct3D 9"));
    if (!gameHWND)
    {
       con->error_message(1, XOR("Failed to get game window!"));
       return 0;
    }
	else return gameHWND;
}

void ProcessMemory::getGameProcessId()
{
	GetWindowThreadProcessId(getGameWindow(), &G.gameProcessId);
	if (!G.gameProcessId)
        con->error_message(2, XOR("Failed to get game process!"));
}

void ProcessMemory::attachGameProcess()
{
	G.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, G.gameProcessId);
	if (!G.hProcess)
		con->error_message(3, XOR("Failed to connect to process!"));
}

void ProcessMemory::sendConsoleCommand(const char* msg)
{
	const HWND m_hEngine = FindWindowA(XOR("Valve001"), 0);
	COPYDATASTRUCT m_cData;
	m_cData.cbData = strlen(msg) + 1;
	m_cData.dwData = 0;
	m_cData.lpData = (void*)msg;
	SendMessageA(m_hEngine, WM_COPYDATA, 0, (LPARAM)&m_cData);
}

bool ProcessMemory::get_module_base_address(const char* moduleName, DWORD* moduleBaseAddress, DWORD* moduleBaseAddressSize) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, G.gameProcessId);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    MODULEENTRY32 moduleEntry;
    moduleEntry.dwSize = sizeof(moduleEntry);
    if (!Module32First(snapshot, &moduleEntry)) {
        CloseHandle(snapshot);
        return false;
    }

    do {
        if (strcmp(moduleEntry.szModule, moduleName) == 0) {
            DWORD* baseAddress = reinterpret_cast<DWORD*>(moduleEntry.modBaseAddr);
            DWORD* baseAddressSize = reinterpret_cast<DWORD*>(moduleEntry.modBaseSize);
            *moduleBaseAddress = reinterpret_cast<DWORD>(baseAddress);
            *moduleBaseAddressSize = reinterpret_cast<DWORD>(baseAddressSize);
            CloseHandle(snapshot);
            return true;
        }
    } while (Module32Next(snapshot, &moduleEntry));

    CloseHandle(snapshot);
    return false;
}

bool ProcessMemory::MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask) 
{
	for (; *szMask; ++szMask, ++bData, ++bMask) {
		if (*szMask == 'x' && *bData != *bMask) {
			return false; 
		}
	}
	return (*szMask == NULL); 
}

DWORD ProcessMemory::FindSignature(DWORD start, DWORD size, const char* sig, const char* mask)
{
	BYTE* data = new BYTE[size]; 
	SIZE_T bytesRead; 

	ReadProcessMemory(G.hProcess, (LPVOID)start, data, size, &bytesRead); 

	for (DWORD i = 0; i < size; i++)
	{
		if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
			delete[] data; 
			return start + i; 
		}
	}
	delete[] data; 
	return NULL; 
}

void ProcessMemory::startMemory()
{
	mem->getGameProcessId();
	mem->attachGameProcess();
    get_module_base_address(XOR("client.dll"), &G.client_dll, &G.client_dll_size);
    get_module_base_address(XOR("engine.dll"), &G.engine_dll, &G.engine_dll_size);
	get_module_base_address(XOR("vstdlib.dll"), &G.vstdlib_dll, &G.vstdlib_dll_size);
}