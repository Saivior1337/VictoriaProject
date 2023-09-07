#pragma once
#include "Headers.h"

struct Vector3
{
	float x, y, z;
};

namespace LocalPlayer 
{
	extern DWORD	LocalBase();
	extern DWORD    GetGlowObjects();
	extern int		LocalHealth();
	extern int		LocalFlags();
	extern int		LocalCrosshairId();
	extern int		LocalTeam();
	extern float	LocalFlashAlpha();
	extern bool		IsScoped();
	extern bool     IsLocalMoving();
	extern Vector3  LocalVelocity();
}

namespace Entity
{
	extern DWORD    GetEntityBase(int index);
	extern int		getClassID(DWORD entity);
	extern int		GetGlowIndex(DWORD entity);
	extern int		GetEntityTeam(DWORD entity);
	extern int		GetEntityHealth(DWORD entity);
	extern bool	    IsEntityAlive(DWORD entity);
	extern bool		IsEntityValid(DWORD entity);
}