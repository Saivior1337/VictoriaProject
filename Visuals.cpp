#include "Visuals.h"

Visuals * iVisuals;
GlowStruct EGlow;
clrRGB clr;

GlowStruct Visuals::SetGlowColor(GlowStruct Glow, DWORD entity)
{

		RGB colorEnemy;
		RGB colorFriend;
		colorEnemy = iUtils->hexToRgb(svg.colorEnemyGlow);
		colorFriend = iUtils->hexToRgb(svg.colorFriendGlow);


		switch (svg.checkboxGlowFriend)
		{
		case TRUE:
			if (LocalPlayer::LocalTeam() != Entity::GetEntityTeam(entity))
			{
				if (svg.checkboxGlowEnemy)
				{
					Glow.r = colorEnemy.r / 255.0f;
					Glow.g = colorEnemy.g / 255.0f;
					Glow.b = colorEnemy.b / 255.0f;
					Glow.a = 0.8f;
					Glow.glowStyle = svg.enemyGlowStyle;
				}
			}
			else
			{
				Glow.r = colorFriend.r / 255.0f;
				Glow.g = colorFriend.g / 255.0f;
				Glow.b = colorFriend.b / 255.0f;
				Glow.a = 0.8f;
				Glow.glowStyle = svg.friendGlowStyle;
			}
		case FALSE:
			if (LocalPlayer::LocalTeam() != Entity::GetEntityTeam(entity))
			{
				if (!svg.checkboxGlowHealth)
				{
					if (svg.checkboxGlowEnemy)
					{
						Glow.r = colorEnemy.r / 255.0f;
						Glow.g = colorEnemy.g / 255.0f;
						Glow.b = colorEnemy.b / 255.0f;
						Glow.a = 0.8f;
						Glow.glowStyle = svg.enemyGlowStyle;
					}
				}
				else
				{
					if (svg.checkboxGlowEnemy)
					{
						Glow.r = Entity::GetEntityHealth(entity) * -0.01 + 1;
						Glow.g = Entity::GetEntityHealth(entity) * 0.01;
						Glow.b = 0.0f;
						Glow.a = 0.8f;
						Glow.glowStyle = svg.enemyGlowStyle;
					}
				}
			}
		}
		Glow.m_bRenderWhenOccluded = true;
		Glow.m_bRenderWhenUnoccluded = false;

	return Glow;
}


void Visuals::Glow(DWORD entity)
{

	EGlow = vm::read<GlowStruct>(G.hProcess, LocalPlayer::GetGlowObjects() + (Entity::GetGlowIndex(entity) * 0x38));
	EGlow = iVisuals->SetGlowColor(EGlow, entity);
	vm::write<GlowStruct>(G.hProcess, LocalPlayer::GetGlowObjects() + (Entity::GetGlowIndex(entity) * 0x38), EGlow);
}

void Visuals::Chams(DWORD entity)
{
	RGB colorEnemy;
	RGB colorFriend;
	colorEnemy = iUtils->hexToRgb(svg.colorEnemyChams);
	colorFriend = iUtils->hexToRgb(svg.colorFriendChams);
	if (LocalPlayer::LocalTeam() != Entity::GetEntityTeam(entity))
	{
		clr.r = colorEnemy.r;
		clr.g = colorEnemy.g;
		clr.b = colorEnemy.b;
	}
	else
	{
		clr.r = colorFriend.r;
		clr.g = colorFriend.g;
		clr.b = colorFriend.b;
	}
	vm::write<clrRGB>(G.hProcess, entity + OFF.m_clrRender, clr);
}

void Visuals::ResetChams(DWORD entity)
{
	clr.r = 255;
	clr.g = 255;
	clr.b = 255;
	vm::write<clrRGB>(G.hProcess, entity + OFF.m_clrRender, clr);
}

void Visuals::mat_ambient()
{
	RGB mat_ambient_light_rgb;
	mat_ambient_light_rgb = iUtils->hexToRgb(svg.mapColor);

	if (!svg.checkboxDarkMap)
	{
		iUtils->SetValue(XOR("mat_ambient_light_r"), mat_ambient_light_rgb.r / 255.f);
		iUtils->SetValue(XOR("mat_ambient_light_g"), mat_ambient_light_rgb.g / 255.f);
		iUtils->SetValue(XOR("mat_ambient_light_b"), mat_ambient_light_rgb.b / 255.f);
	}
	else
	{
		iUtils->SetValue(XOR("mat_ambient_light_r"), (mat_ambient_light_rgb.r * -1) / 255.f);
		iUtils->SetValue(XOR("mat_ambient_light_g"), (mat_ambient_light_rgb.g * -1) / 255.f);
		iUtils->SetValue(XOR("mat_ambient_light_b"), (mat_ambient_light_rgb.b * -1) / 255.f);
	}

}

bool Visuals::InternalRadar(DWORD entity)
{
	if (LocalPlayer::LocalTeam() != Entity::GetEntityTeam(entity))
		return vm::write<bool>(G.hProcess, entity + OFF.m_bSpotted, true);
	else
		return false;
}
