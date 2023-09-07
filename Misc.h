#pragma once
#include "Headers.h"

#define FORCE_JUMP_BITMASK (1<<0)

class Misc
{
public:
	void Bhop();
	void convars();
	void convar_fov_cs_debug();
	void Sound();
private:
	int currJumpState{ 0 };
	BYTE onGround = 1;

	HRSRC ResourceBameware = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE1), "WAVE");
	HANDLE ResourceBamewareHandle = LoadResource(NULL, ResourceBameware);
	LPVOID ResourceBamewareVoid = LockResource(ResourceBamewareHandle);

	HRSRC ResourceFatality = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE2), "WAVE");
	HANDLE ResourceFatalityHandle = LoadResource(NULL, ResourceFatality);
	LPVOID ResourceFatalityVoid = LockResource(ResourceFatalityHandle);

	HRSRC ResourcePop = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE3), "WAVE");
	HANDLE ResourcePopHandle = LoadResource(NULL, ResourcePop);
	LPVOID ResourcePopVoid = LockResource(ResourcePopHandle);

	HRSRC ResourcePunch = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE4), "WAVE");
	HANDLE ResourcePunchHandle = LoadResource(NULL, ResourcePunch);
	LPVOID ResourcePunchVoid = LockResource(ResourcePunchHandle);

	HRSRC ResourceRifk = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE5), "WAVE");
	HANDLE ResourceRifkHandle = LoadResource(NULL, ResourceRifk);
	LPVOID ResourceRifkVoid = LockResource(ResourceRifkHandle);

	HRSRC ResourceSkeet = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE6), "WAVE");
	HANDLE ResourceSkeetHandle = LoadResource(NULL, ResourceSkeet);
	LPVOID ResourceSkeetVoid = LockResource(ResourceSkeetHandle);

	HRSRC ResourceStapler = FindResource(NULL, MAKEINTRESOURCE(IDR_WAVE7), "WAVE");
	HANDLE ResourceStaplerHandle = LoadResource(NULL, ResourceStapler);
	LPVOID ResourceStaplerVoid = LockResource(ResourceStaplerHandle);
};

extern Misc * iMisc;