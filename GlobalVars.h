#pragma once
#include "Headers.h"

class GlobalVars 
{
public:
	HWND consoleWindow = NULL;
	RECT consoleRect = {0, 0, 0, 0};
	HANDLE consoleHandle = NULL;
	const char* consoleWindowName = "VictoriaProject";
	int consoleWidth = 600;
	int consoleHeight = 300;
	int screenX = 0;
	int screenY = 0;
	DWORD client_dll = NULL;
	DWORD client_dll_size = NULL;
	DWORD engine_dll = NULL;
	DWORD engine_dll_size = NULL;
	DWORD vstdlib_dll = NULL;
	DWORD vstdlib_dll_size = NULL;
	DWORD gameProcessId = NULL;
	HANDLE hProcess = NULL;
	//colors
	WORD COLOR_BLACK = 0xF0;
	WORD COLOR_BLUE = 0x1;
	WORD COLOR_GREEN = 0x2;
	WORD COLOR_CYAN = 0x3;
	WORD COLOR_RED = 0x4;
	WORD COLOR_MAGENTA = 0x5;
	WORD COLOR_BROWN = 0x6;
	WORD COLOR_LIGHTGREY_DEFAULT = 0x7;
	WORD COLOR_DARKGREY = 0x8;
	WORD COLOR_LIGHTBLUE = 0x9;
	WORD COLOR_LIGHTGREEN = 0xA;
	WORD COLOR_LIGHTCYAN = 0xB;
	WORD COLOR_LIGHTRED = 0xC;
	WORD COLOR_YELLOW = 0xE;
	WORD COLOR_WHITE = 0xF;
};

class ServerConfiguration
{
public:
	bool isAimbotEnabled = false;
	bool isTriggerEnabled = false;
	bool isMiscEnabled = false;
	bool checkboxGlow = false;
	bool checkboxGlowEnemy = false;
	bool checkboxGlowFriend = false;
	bool checkboxGlowHealth = false;
	bool checkboxRadar = false;
	bool checkboxChams = false;
	bool checkboxBhop = false;
	bool checkboxGPreview = false;
	bool checkboxDarkMap = false;
	bool checkboxPlayerViewmodel = false;
	bool checkboxRecoilCrosshair = false;
	bool checkboxForceSniperCrosshair = false;
	bool checkboxWeaponDebugAccuracy = false;
	bool checkboxHitsound = false;
	bool checkboxKnifeModel = false;
	std::string colorEnemyGlow = "#FFFFFF";
	std::string colorFriendGlow = "#FFFFFF";
	std::string colorEnemyChams = "#FFFFFF";
	std::string colorFriendChams = "#FFFFFF";
	std::string mapColor = "#FFFFFF";
	int enemyGlowStyle = 0;
	int friendGlowStyle = 0;
	int playerFOV = 0;
	int playerViewmodelFOV = 0;
	int playerViewmodelX = 0;
	int playerViewmodelY = 0;
	int playerViewmodelZ = 0;
	int selectedHitsound = 1;
	int selectedKnifeModel = 1;
};


class COffsets
{
public:
	DWORD dwLocalPlayer;
	DWORD dwEntityList;
	DWORD dwGlowObjectManager;
	DWORD dwForceJump;
	DWORD dwForceAttack;
	DWORD dwWorld, dwClasses, totalHitsOnServer, nModelIndex, ClientCMD;
	DWORD m_iGlowIndex, m_vecOrigin, m_vecViewOffset, m_viewPunchAngle, m_iFOV, m_iFOVStart, m_hActiveWeapon, dwClientState_MapDirectory;
	DWORD m_dwBoneMatrix, m_clrRender, m_aimPunchAngle, m_aimPunchAngleVel, m_hMyWeapons;
	DWORD dwClientState, dwClientState_ViewAngles, dwRadarBase, m_bDormant, dwClientState_PlayerInfo, dwClientState_Map, dwGameDir;
	DWORD m_bSpotted, m_bSpottedByMask, m_fFlags, m_iCrosshairId, dwViewMatrix, model_ambient_min, m_hViewModel;
	DWORD m_iHealth, m_iTeamNum, m_vecVelocity, m_bIsDefusing, m_iItemDefinitionIndex, m_bIsScoped, m_flFlashMaxAlpha, m_bGunGameImmunity, m_ArmorValue, dwGameRulesProxy, m_bBombPlanted, m_nViewModelIndex;
	DWORD m_iItemIDHigh, m_OriginalOwnerXuidLow, m_OriginalOwnerXuidHigh, m_nFallbackPaintKit, m_nFallbackSeed, m_nFallbackStatTrak, m_flFallbackWear, m_szCustomName, m_iEntityQuality, m_flFlashDuration, m_bInReload;
	DWORD clientstate_delta_ticks;
};


extern GlobalVars G;
extern ServerConfiguration svg;
extern COffsets OFF;