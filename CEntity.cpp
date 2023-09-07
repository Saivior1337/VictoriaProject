#include "CEntity.h"

DWORD LocalPlayer::LocalBase()
{
	return vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwLocalPlayer);
}

DWORD LocalPlayer::GetGlowObjects()
{
	return vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwGlowObjectManager);
}

int LocalPlayer::LocalHealth()
{
	return vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_iHealth);
}

int LocalPlayer::LocalFlags()
{
	return vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_fFlags);
}

int LocalPlayer::LocalCrosshairId()
{
	return vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_iCrosshairId);
}

int LocalPlayer::LocalTeam()
{
	return vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_iTeamNum);
}

float LocalPlayer::LocalFlashAlpha()
{
	return vm::read<float>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_flFlashMaxAlpha);
}

bool LocalPlayer::IsScoped()
{
	return vm::read<bool>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_bIsScoped);
}

bool LocalPlayer::IsLocalMoving()
{
	float Velocity = LocalPlayer::LocalVelocity().x + LocalPlayer::LocalVelocity().y + LocalPlayer::LocalVelocity().z;
	if (!Velocity)
		return false;
	else
		return true;
}

Vector3 LocalPlayer::LocalVelocity()
{
	return vm::read<Vector3>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_vecVelocity);
}

DWORD Entity::GetEntityBase(int index)
{
	return vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwEntityList + (index * 0x10));
}

int Entity::GetGlowIndex(DWORD entity)
{
	return vm::read<int>(G.hProcess, entity + OFF.m_iGlowIndex);
}

int Entity::GetEntityTeam(DWORD entity)
{
	return vm::read<int>(G.hProcess, entity + OFF.m_iTeamNum);
}

int Entity::GetEntityHealth(DWORD entity)
{
	return vm::read<int>(G.hProcess, entity + OFF.m_iHealth);
}

bool Entity::IsEntityAlive(DWORD entity)
{
	if (Entity::GetEntityHealth(entity) > 0 && Entity::GetEntityHealth(entity) <= 100)
		return true;
	else
		return false;
}

bool Entity::IsEntityValid(DWORD entity)
{
	bool dormant = vm::read<bool>(G.hProcess, entity + OFF.m_bDormant);
	if ((Entity::IsEntityAlive(entity) && Entity::GetEntityTeam(entity) != 0) && !dormant)
		return true;
	else
		return false;
}