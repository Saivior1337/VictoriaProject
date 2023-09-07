#include "Utils.h"

Utils * iUtils;


RGB Utils::hexToRgb(std::string hexValue)
{
    hexValue.erase(0, 1);
    std::istringstream iss(hexValue);
    int hexInt;
    iss >> std::hex >> hexInt;
    RGB rgb = {
        (hexInt >> 16) & 0xFF,
        (hexInt >> 8) & 0xFF,
        hexInt & 0xFF
    };
    return rgb;
}


bool Utils::string2bool(std::string string_value)
{
    if (string_value == XOR("true"))
        return true;
    else
        return false;
}

int Utils::GetStringHash(const char* name)
{
	int codes[256];
	DWORD convar_name_hash_table = vm::read<DWORD>(G.hProcess, mem->FindSignature(G.vstdlib_dll, G.vstdlib_dll_size, XOR("\x8B\x3C\x85"), XOR("xxx")) + 3) - G.vstdlib_dll;
	vm::read(G.hProcess, G.vstdlib_dll + convar_name_hash_table, &codes);
	
	int v2 = 0; 
	int v3 = 0; 
	for (unsigned int i = 0; i < strlen(name); i += 2)
	{
		v3 = codes[v2 ^ toupper(name[i])]; 
		if (i + 1 == strlen(name))
			break; 
		v2 = codes[v3 ^ toupper(name[i + 1])]; 
	}
	return v2 | (v3 << 8);
}

DWORD Utils::GetConVarAddress(const char* name)
{
	int hash = GetStringHash(name); 
	DWORD interface_engine_cvar = vm::read<DWORD>(G.hProcess, mem->FindSignature(G.vstdlib_dll, G.vstdlib_dll_size, XOR("\x8B\x0D\x00\x00\x00\x00\xC7\x05"), XOR("xx????xx")) + 0x2) - G.vstdlib_dll; 
	DWORD CvarEngine = vm::read<DWORD>(G.hProcess, G.vstdlib_dll + interface_engine_cvar); 
	DWORD Pointer = vm::read<DWORD>(G.hProcess, vm::read<DWORD>(G.hProcess, CvarEngine + 0x34) + ((BYTE)hash * 4)); 
	while (Pointer)
	{
		if (vm::read<DWORD>(G.hProcess, Pointer) == hash)
		{
			DWORD ConVarPointer = vm::read<DWORD>(G.hProcess, Pointer + 0x4); 
			char* varname[32];
			vm::read(G.hProcess, vm::read<DWORD>(G.hProcess, ConVarPointer + 0xC), &varname); 
			if (!strcmp((char*)varname, name))
			{
				return ConVarPointer; 
			}
		}
		Pointer = vm::read<DWORD>(G.hProcess, Pointer + 0xC); 
	}
	return false;
}

std::string Utils::getValue(const char* name)
{
	char dummy[255]; 
	vm::read(G.hProcess, vm::read<DWORD>(G.hProcess, GetConVarAddress(name) + 0x24), &dummy); 
	return std::string(dummy); 
}

void Utils::SetValue(const char* name, float val)
{
	DWORD addr = GetConVarAddress(name); 
	vm::write<int>(G.hProcess, addr + 0x2C, *(int*)&val ^ addr); 
}

void Utils::SetValue(const char* name, int val)
{
	DWORD addr = GetConVarAddress(name); 
	vm::write<int>(G.hProcess, addr + 0x30, val ^ addr); 
}

UINT Utils::GetModelIndexByName(const char* modelName)
{
	DWORD cstate = vm::read<DWORD>(G.hProcess, G.engine_dll + OFF.dwClientState);
	DWORD nst = vm::read<DWORD>(G.hProcess, cstate + 0x52a4);
	DWORD nsd = vm::read<DWORD>(G.hProcess, nst + 0x40);
	DWORD nsdi = vm::read<DWORD>(G.hProcess, nsd + 0xC);

	for (UINT i = 0; i < 1024; i++)
	{
		DWORD nsdi_i = vm::read<DWORD>(G.hProcess, nsdi + 0xC + i * 0x34);
		char str[128] = { 0 };
		vm::read(G.hProcess, nsdi_i, &str);
		if (str)
		{
			if (_stricmp(str, modelName) == 0)
			{
				return i;
			}
		}
	}
	return 0;
}