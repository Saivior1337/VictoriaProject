#pragma once
#include "Headers.h"

struct RGB { int r, g, b; };

class Utils
{
public:
    RGB hexToRgb(std::string hexValue);
    bool string2bool(std::string string_value);
    int GetStringHash(const char* name);
    DWORD GetConVarAddress(const char* name);
    std::string getValue(const char* name);
    void SetValue(const char* name, float val);
    void SetValue(const char* name, int val);
    UINT GetModelIndexByName(const char* modelName);
};

extern Utils* iUtils;