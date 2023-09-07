#pragma once
#include "Headers.h"

typedef NTSTATUS(NTAPI* _NtReadVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesRead);
typedef NTSTATUS(NTAPI* _NtWriteVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, LPCVOID Buffer, ULONG NumberOfBytesToWrite, PULONG NumberOfBytesWritten);

class ProcessMemory
{
public:
	HWND getGameWindow();
	void getGameProcessId();
	void attachGameProcess();
	void sendConsoleCommand(const char* msg);
	bool get_module_base_address(const char* moduleName, DWORD* moduleBaseAddress, DWORD* moduleBaseAddressSize);
    bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask);
    DWORD FindSignature(DWORD start, DWORD size, const char* sig, const char* mask);
	void startMemory();

};

namespace vm
{
    template <class dataType>
    dataType read(HANDLE hProcess, DWORD addressToRead)
    {
        bool initrvm = false;
        _NtReadVirtualMemory NtReadVirtualMemory;
        if (!initrvm) { NtReadVirtualMemory = (_NtReadVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtReadVirtualMemory"); initrvm = true; }
        dataType valToRead;
        DWORD oldProtect = 0; NTSTATUS status = 0;
        status = NtReadVirtualMemory(hProcess, PVOID(addressToRead), &valToRead, sizeof(dataType), NULL);
        VirtualProtectEx(hProcess, (PVOID)addressToRead, sizeof(dataType), oldProtect, NULL);
        return valToRead;
    }

    template <class dataType>
    void read(HANDLE hProcess, DWORD addressToRead, dataType* valToRead)
    {
        bool initrvm = false;
        _NtReadVirtualMemory NtReadVirtualMemory;
        if (!initrvm) { NtReadVirtualMemory = (_NtReadVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtReadVirtualMemory"); initrvm = true; }
        DWORD oldProtect = 0; NTSTATUS status = 0;
        VirtualProtectEx(hProcess, (PVOID)addressToRead, sizeof(dataType), PAGE_EXECUTE_READWRITE, &oldProtect);
        status = NtReadVirtualMemory(hProcess, PVOID(addressToRead), valToRead, sizeof(dataType), NULL);
        VirtualProtectEx(hProcess, (PVOID)addressToRead, sizeof(dataType), oldProtect, NULL);
    }

    template <class dataType>
    BOOL write(HANDLE hProcess, DWORD addressToWrite, dataType valToWrite)
    {
        bool initwvm = false;
        _NtWriteVirtualMemory NtWriteVirtualMemory;
        if (!initwvm) { NtWriteVirtualMemory = (_NtWriteVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtWriteVirtualMemory"); initwvm = true; }
        DWORD oldProtect = 0; NTSTATUS status = 0;
        VirtualProtectEx(hProcess, (PVOID)addressToWrite, sizeof(dataType), PAGE_EXECUTE_READWRITE, &oldProtect);
        status = NtWriteVirtualMemory(hProcess, (PVOID)addressToWrite, &valToWrite, sizeof(dataType), NULL);
        return VirtualProtectEx(hProcess, (PVOID)addressToWrite, sizeof(dataType), oldProtect, NULL);
    }

};

extern ProcessMemory * mem;
