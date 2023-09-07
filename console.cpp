#include "console.h"

console * con;

void console::setupConsole()
{
	G.consoleWindow = GetConsoleWindow();
	G.consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetWindowRect(G.consoleWindow, &G.consoleRect);
	G.screenX = GetSystemMetrics(SM_CXSCREEN);
	G.screenY = GetSystemMetrics(SM_CYSCREEN);
	SetConsoleTitle(G.consoleWindowName);
	MoveWindow(G.consoleWindow, (G.screenX / 2) - (G.consoleWidth / 2), (G.screenY / 2) - (G.consoleHeight + 100), G.consoleWidth, G.consoleHeight, true);
	mem->sendConsoleCommand(XOR("clear"));
	mem->sendConsoleCommand(XOR("echo [VictoriaProject]: Successfully injected!"));
	api->OpenSteamOverlayBrowser("http://127.0.0.1/");
}

void console::TerminateConsole()
{
	if (GetAsyncKeyState(VK_END) & 1)
	{
		SteamAPI_Shutdown();
		exit(0);
	}
}

void console::printColoredText(const char* msg, WORD color)
{
	SetConsoleTextAttribute(G.consoleHandle, color);
	std::printf(msg);
	SetConsoleTextAttribute(G.consoleHandle, G.COLOR_LIGHTGREY_DEFAULT);
}

void console::clear_console_screen()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	if (G.consoleHandle == INVALID_HANDLE_VALUE) return;

	if (!GetConsoleScreenBufferInfo(G.consoleHandle, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(G.consoleHandle, (TCHAR)' ', cellCount, homeCoords, &count)) return;

	if (!FillConsoleOutputAttribute(G.consoleHandle, csbi.wAttributes, cellCount, homeCoords, &count)) return;

	SetConsoleCursorPosition(G.consoleHandle, homeCoords);
}

void console::error_message(int errorCode, const char* msg)
{
	con->clear_console_screen();
	SetConsoleTextAttribute(G.consoleHandle, G.COLOR_LIGHTRED);
	std::cout << XOR("Error #") << errorCode << XOR(" | ") << msg;
	std::this_thread::sleep_for(5000ms);
	exit(0);
}