#include "Models.h"

Models* iModels;

unsigned long __stdcall Models::SetKnife(void*)
{
	int knifeIndex;
	int gmibncounter = 1000;
	int knifeID;
	const char* modelName = "";
	while (true)
	{
		if (svg.checkboxKnifeModel)
		{
			switch (svg.selectedKnifeModel)
			{
			case 1:
				modelName = "models/weapons/v_knife_m9_bay.mdl";
				knifeIndex = 508;
				break;
			case 2:
				modelName = "models/weapons/v_knife_karam.mdl";
				knifeIndex = 507;
				break;
			case 3:
				modelName = "models/weapons/v_knife_flip.mdl";
				knifeIndex = 505;
				break;
			case 4:
				modelName = "models/weapons/v_knife_ghost.mdl";
				knifeIndex = 505;
				break;
			case 5:
				modelName = "models/weapons/v_knife_gut.mdl";
				knifeIndex = 506;
				break;
			}


			gmibncounter++;
			if (gmibncounter >= 1000)
			{
				knifeID = iUtils->GetModelIndexByName(modelName);
				gmibncounter = 0;
			}


			for (int i = 0; i < 8; i++)
			{
				WORD WeaponEnt = vm::read<int>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_hMyWeapons + i * 0x4) & 0xFFF;
				int Weapon = vm::read<int>(G.hProcess, (int)G.client_dll + OFF.dwEntityList + (WeaponEnt - 1) * 0x10);
				if (Weapon == 0)
				{
					continue;
				}
				short WeaponID = vm::read<short>(G.hProcess, Weapon + OFF.m_iItemDefinitionIndex);

				switch (WeaponID)
				{
				case 0:
					continue;
					break;
				case 42:
				case 59:
					vm::write<WORD>(G.hProcess, Weapon + OFF.m_iItemDefinitionIndex, knifeIndex);
					break;
				}

			}

			short mywepID = vm::read<short>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_hActiveWeapon) & 0xFFF;
			short weaponIndex = vm::read<short>(G.hProcess, vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwEntityList + (mywepID - 1) * 0x10) + OFF.m_iItemDefinitionIndex);
			if (weaponIndex == knifeIndex)
			{
				short activeViewModel = vm::read<short>(G.hProcess, LocalPlayer::LocalBase() + OFF.m_hViewModel) & 0xfff;
				DWORD activeViewModelBase = vm::read<DWORD>(G.hProcess, G.client_dll + OFF.dwEntityList + (activeViewModel - 1) * 0x10);
				vm::write<UINT>(G.hProcess, activeViewModelBase + 0x258, knifeID);

			}
			vm::write<int>(G.hProcess, G.engine_dll + 0x174, -1);
		}
		else
		{
			std::this_thread::sleep_for(2000ms);
		}
	}
}