#pragma once
#include "Headers.h"

struct GlowStruct
{
	BYTE nextFreeSlot[0x4];
	BYTE entity[0x4];
	float r;
	float g;
	float b;
	float a;
	BYTE pad0[0x10];
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloomRender;
	int m_nFullBloomStencilTestValue;
	int glowStyle;
};

struct clrRGB 
{
	BYTE r,g,b;
};

class Visuals
{
public:
	GlowStruct SetGlowColor(GlowStruct Glow, DWORD entity);
	void Glow(DWORD entity);
	void Chams(DWORD entity);
	void ResetChams(DWORD entity);
	void mat_ambient();
	bool InternalRadar(DWORD entity);
};

extern Visuals * iVisuals;