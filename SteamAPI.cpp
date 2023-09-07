#include "SteamAPI.h"

SteamAPI* api;

void SteamAPI::OpenSteamOverlayBrowser(const char* url)
{
    SteamFriends()->ActivateGameOverlayToWebPage(url);
}
