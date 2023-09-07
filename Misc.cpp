#include "Misc.h"

Misc * iMisc;

void Misc::Bhop()
{
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (LocalPlayer::IsLocalMoving())
        {
            currJumpState = vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwForceJump);
            onGround = vm::read<BYTE>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_fFlags);
            if (onGround & (1 << 0))
            {
                currJumpState |= FORCE_JUMP_BITMASK;
                vm::write<BYTE>(G.hProcess, G.client_dll + OFF.dwForceJump, currJumpState);
            }
            else
            {
                currJumpState &= ~FORCE_JUMP_BITMASK;
                vm::write<BYTE>(G.hProcess, G.client_dll + OFF.dwForceJump, currJumpState);
            }
        }
    }
}

int hits = 0;

void Misc::Sound()
{
	int totalhits = vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + 0x103f8);
	if (totalhits > hits)
	{
		hits = totalhits;
        switch (svg.selectedHitsound)
        {
        case 1:
            sndPlaySound((LPCSTR)ResourceBamewareVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 2:
            sndPlaySound((LPCSTR)ResourceFatalityVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 3:
            sndPlaySound((LPCSTR)ResourcePopVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 4:
            sndPlaySound((LPCSTR)ResourcePunchVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 5:
            sndPlaySound((LPCSTR)ResourceRifkVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 6:
            sndPlaySound((LPCSTR)ResourceSkeetVoid, SND_MEMORY | SND_ASYNC);
            break;
        case 7:
            sndPlaySound((LPCSTR)ResourceStaplerVoid, SND_MEMORY | SND_ASYNC);
            break;
        }
		
	}
	if (totalhits == 0) hits = 0;
}

void Misc::convars()
{
    if (svg.checkboxGPreview)
        iUtils->SetValue(XOR("cl_grenadepreview"), 1);
    else
        iUtils->SetValue(XOR("cl_grenadepreview"), 0);

    if (svg.checkboxPlayerViewmodel)
    {
        iUtils->SetValue(XOR("viewmodel_fov"), svg.playerViewmodelFOV * 1.f);
        iUtils->SetValue(XOR("viewmodel_offset_x"), svg.playerViewmodelX * 1.f);
        iUtils->SetValue(XOR("viewmodel_offset_y"), svg.playerViewmodelY * 1.f);
        iUtils->SetValue(XOR("viewmodel_offset_z"), svg.playerViewmodelZ * 1.f);
    }

    if (svg.checkboxRecoilCrosshair)
        iUtils->SetValue(XOR("cl_crosshair_recoil"), 1.f);
    else
        iUtils->SetValue(XOR("cl_crosshair_recoil"), 0.f);

    if (svg.checkboxForceSniperCrosshair)
        iUtils->SetValue(XOR("weapon_debug_spread_show"), 3);
    else
        iUtils->SetValue(XOR("weapon_debug_spread_show"), 0);

    if (svg.checkboxWeaponDebugAccuracy)
    {
        iUtils->SetValue(XOR("cl_weapon_debug_show_accuracy"), 2);
        iUtils->SetValue(XOR("cl_weapon_debug_show_accuracy_duration"), 0.9f);
    }
    else
    {
        iUtils->SetValue(XOR("cl_weapon_debug_show_accuracy"), 0);
    }
}

void Misc::convar_fov_cs_debug()
{
    if (!LocalPlayer::IsScoped())
        iUtils->SetValue(XOR("fov_cs_debug"), svg.playerFOV * 1.f);
    else
        iUtils->SetValue(XOR("fov_cs_debug"), 0.f);
}