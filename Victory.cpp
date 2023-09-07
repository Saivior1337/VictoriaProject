#include "Headers.h"


int main()
{

    SteamAPI* api = new SteamAPI();
    SteamAPI_Init();

    Utils* iUtils = new Utils();
    server* web = new server();
    ProcessMemory* mem = new ProcessMemory();
    console* con = new console();
    OffsetManager* offsets = new OffsetManager();
    Misc* iMisc = new Misc();
    Models* iModels = new Models();

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)web->session, NULL, NULL, NULL);
    mem->startMemory();
    con->setupConsole();
    offsets->downloadOffsets();
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)iModels->SetKnife, NULL, NULL, NULL);

    while (true)
    {
        con->TerminateConsole();
        web->OpenWebMenu();

        if (svg.isMiscEnabled) 
        { 
            if (svg.checkboxBhop) { iMisc->Bhop(); }
            if (svg.checkboxHitsound) { iMisc->Sound(); }
            iMisc->convar_fov_cs_debug();
        }
        for (int i = 0; i < 64; i++)
        {
            DWORD Entity = Entity::GetEntityBase(i);
            if (Entity != NULL)
            {
                if (svg.checkboxGlow) { iVisuals->Glow(Entity);}
                if (svg.checkboxChams) { iVisuals->Chams(Entity);}
                else { iVisuals->ResetChams(Entity); }

                if (svg.checkboxRadar) { iVisuals->InternalRadar(Entity);}
            }
        }
        std::this_thread::sleep_for(1ms);
    }
    
    std::cin.get();
    SteamAPI_Shutdown();
    return 0;
}
