#include "OffsetManager.h"

OffsetManager* offsets;

void OffsetManager::downloadOffsets()
{
	URLDownloadToFile(NULL, XOR("https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.json"), XOR("csgo.json"), NULL, NULL);

	std::ifstream files{ XOR("csgo.json") };
	if (!files) { con->error_message(5, "Failed to download offsets!"); }
	json offset = json::parse(files);
	files.close();

	OFF.m_aimPunchAngle = offset[XOR("netvars")][XOR("m_aimPunchAngle")];
	OFF.m_aimPunchAngleVel = offset[XOR("netvars")][XOR("m_aimPunchAngleVel")];
	OFF.m_bSpotted = offset[XOR("netvars")][XOR("m_bSpotted")];
	OFF.m_bSpottedByMask = offset[XOR("netvars")][XOR("m_bSpottedByMask")];
	OFF.m_clrRender = offset[XOR("netvars")][XOR("m_clrRender")];
	OFF.m_dwBoneMatrix = offset[XOR("netvars")][XOR("m_dwBoneMatrix")];
	OFF.m_fFlags = offset[XOR("netvars")][XOR("m_fFlags")];
	OFF.m_hActiveWeapon = offset[XOR("netvars")][XOR("m_hActiveWeapon")];
	OFF.m_hMyWeapons = offset[XOR("netvars")][XOR("m_hMyWeapons")];
	OFF.m_iCrosshairId = offset[XOR("netvars")][XOR("m_iCrosshairId")];
	OFF.m_iFOV = offset[XOR("netvars")][XOR("m_iFOV")];
	OFF.m_iFOVStart = offset[XOR("netvars")][XOR("m_iFOVStart")];
	OFF.m_iGlowIndex = offset[XOR("netvars")][XOR("m_iGlowIndex")];
	OFF.m_vecOrigin = offset[XOR("netvars")][XOR("m_vecOrigin")];
	OFF.m_vecViewOffset = offset[XOR("netvars")][XOR("m_vecViewOffset")];
	OFF.m_viewPunchAngle = offset[XOR("netvars")][XOR("m_viewPunchAngle")];
	OFF.dwClientState = offset[XOR("signatures")][XOR("dwClientState")];
	OFF.dwClientState_ViewAngles = offset[XOR("signatures")][XOR("dwClientState_ViewAngles")];
	OFF.dwRadarBase = offset[XOR("signatures")][XOR("dwRadarBase")];
	OFF.dwViewMatrix = offset[XOR("signatures")][XOR("dwViewMatrix")];
	OFF.m_bDormant = offset[XOR("signatures")][XOR("m_bDormant")];
	OFF.model_ambient_min = offset[XOR("signatures")][XOR("model_ambient_min")];
	OFF.m_iHealth = offset[XOR("netvars")][XOR("m_iHealth")];
	OFF.m_iTeamNum = offset[XOR("netvars")][XOR("m_iTeamNum")];
	OFF.m_vecVelocity = offset[XOR("netvars")][XOR("m_vecVelocity")];
	OFF.m_bIsDefusing = offset[XOR("netvars")][XOR("m_bIsDefusing")];
	OFF.m_iItemDefinitionIndex = offset[XOR("netvars")][XOR("m_iItemDefinitionIndex")];
	OFF.m_bIsScoped = offset[XOR("netvars")][XOR("m_bIsScoped")];
	OFF.m_flFlashMaxAlpha = offset[XOR("netvars")][XOR("m_flFlashMaxAlpha")];
	OFF.m_bGunGameImmunity = offset[XOR("netvars")][XOR("m_bGunGameImmunity")];
	OFF.m_ArmorValue = offset[XOR("netvars")][XOR("m_ArmorValue")];
	OFF.dwClientState_PlayerInfo = offset[XOR("signatures")][XOR("dwClientState_PlayerInfo")];
	OFF.dwLocalPlayer = offset[XOR("signatures")][XOR("dwLocalPlayer")];
	OFF.dwEntityList = offset[XOR("signatures")][XOR("dwEntityList")];
	OFF.dwGlowObjectManager = offset[XOR("signatures")][XOR("dwGlowObjectManager")];
	OFF.dwForceJump = offset[XOR("signatures")][XOR("dwForceJump")];
	OFF.dwForceAttack = offset[XOR("signatures")][XOR("dwForceAttack")];
	OFF.dwClientState_MapDirectory = offset[XOR("signatures")][XOR("dwClientState_MapDirectory")];
	OFF.dwClientState_Map = offset[XOR("signatures")][XOR("dwClientState_Map")];
	OFF.dwGameDir = offset[XOR("signatures")][XOR("dwGameDir")];
	OFF.dwGameRulesProxy = offset[XOR("signatures")][XOR("dwGameRulesProxy")];
	OFF.m_bBombPlanted = offset[XOR("netvars")][XOR("m_bBombPlanted")];
	OFF.m_hViewModel = offset[XOR("netvars")][XOR("m_hViewModel")];
	OFF.m_nViewModelIndex = offset[XOR("netvars")][XOR("m_nViewModelIndex")];
	OFF.m_iItemIDHigh = offset[XOR("netvars")][XOR("m_iItemIDHigh")];
	OFF.m_OriginalOwnerXuidLow = offset[XOR("netvars")][XOR("m_OriginalOwnerXuidLow")];
	OFF.m_OriginalOwnerXuidHigh = offset[XOR("netvars")][XOR("m_OriginalOwnerXuidHigh")];
	OFF.m_nFallbackPaintKit = offset[XOR("netvars")][XOR("m_nFallbackPaintKit")];
	OFF.m_nFallbackSeed = offset[XOR("netvars")][XOR("m_nFallbackSeed")];
	OFF.m_nFallbackStatTrak = offset[XOR("netvars")][XOR("m_nFallbackStatTrak")];
	OFF.m_flFallbackWear = offset[XOR("netvars")][XOR("m_flFallbackWear")];
	OFF.m_szCustomName = offset[XOR("netvars")][XOR("m_szCustomName")];
	OFF.m_iEntityQuality = offset[XOR("netvars")][XOR("m_iEntityQuality")];
	OFF.m_flFlashDuration = offset[XOR("netvars")][XOR("m_flFlashDuration")];
	OFF.m_bInReload = offset[XOR("netvars")][XOR("m_bInReload")];
	OFF.clientstate_delta_ticks = offset[XOR("signatures")][XOR("clientstate_delta_ticks")];

	if (OFF.dwLocalPlayer != NULL)
		remove(XOR("csgo.json"));
	else
		con->error_message(6, "Csgo.json is empty!");
}