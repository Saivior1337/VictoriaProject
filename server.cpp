#include "server.h"

server * web;
Server svr;

unsigned __stdcall server::session(void*)
{
    svr.Get("/main", [](const Request& req, Response& res)
        {
            std::ifstream file(XOR("web/index.html"));
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                res.set_content(buffer.str(), XOR("text/html"));
                res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));
            }
            else
            {
                res.set_content(XOR("Unable to open file"), XOR("text/plain"));
            }
        });

    svr.Get("/style.css", [](const Request& req, Response& res)
        {
            std::ifstream file(XOR("web/style.css"));
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                res.set_content(buffer.str(), XOR("text/css"));
                res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));
            }
            else
            {
                res.set_content(XOR("Unable to open file"), XOR("text/plain"));
            }
        });

    svr.Get("/app.js", [](const Request& req, Response& res)
        {
            std::ifstream file(XOR("web/js/app.js"));
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                res.set_content(buffer.str(), XOR("text/javascript"));
                res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));
            }
            else
            {
                res.set_content(XOR("Unable to open file"), XOR("text/plain"));
            }
        });

    svr.Get("/script.js", [](const Request& req, Response& res)
        {
            std::ifstream file(XOR("web/js/script.js"));
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                res.set_content(buffer.str(), XOR("text/javascript"));
                res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));
            }
            else
            {
                res.set_content(XOR("Unable to open file"), XOR("text/plain"));
            }
        });


    svr.Post("/main", [](const Request& req, Response& res) {
        std::ifstream file(XOR("web/index.html"));
        if (file.is_open()) {
            std::stringstream buffer;
            std::string enemyGlowStyleStr, friendGlowStyleStr, pfovStr, pViewmodelFOVStr, pViewmodelXStr, pViewmodelYStr, pViewmodelZStr, hitsoundStr, knifemodelStr;

            buffer << file.rdbuf();
            res.set_content(buffer.str(), XOR("text/html"));
            res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));

            json jsonData = json::parse(req.body);
            svg.isAimbotEnabled = jsonData["isAimbotEnabled"];
            svg.isTriggerEnabled = jsonData["isTriggerEnabled"];
            svg.isMiscEnabled = jsonData["isMiscEnabled"];
            svg.checkboxGlow = jsonData["checkboxGlow"];
            svg.checkboxGlowEnemy = jsonData["checkboxGlowEnemy"];
            svg.checkboxGlowFriend = jsonData["checkboxGlowFriend"];
            svg.colorEnemyGlow = jsonData["colorEnemyGlow"];
            svg.colorFriendGlow = jsonData["colorFriendGlow"];
            svg.checkboxGlowHealth = jsonData["checkboxGlowHP"];
            svg.checkboxRadar = jsonData["checkboxRadar"];
            svg.checkboxChams = jsonData["checkboxChams"];
            svg.colorEnemyChams = jsonData["colorEnemyChams"];
            svg.colorFriendChams = jsonData["colorFriendChams"];
            svg.checkboxBhop = jsonData["checkboxBhop"];
            enemyGlowStyleStr = jsonData["glowEnemyStyle"];
            friendGlowStyleStr = jsonData["glowFriendStyle"];
            svg.checkboxGPreview = jsonData["checkboxGPreview"];
            svg.mapColor = jsonData["mapColor"];
            svg.checkboxDarkMap = jsonData["darkMap"];

            pfovStr = jsonData["playerFOV"];
            svg.playerFOV = std::atoi(pfovStr.c_str());

            svg.checkboxPlayerViewmodel = jsonData["playerViewmodel"];

            pViewmodelFOVStr = jsonData["playerViewmodelFOV"];
            svg.playerViewmodelFOV = std::atoi(pViewmodelFOVStr.c_str());

            pViewmodelXStr = jsonData["playerViewmodelX"];
            svg.playerViewmodelX = std::atoi(pViewmodelXStr.c_str());

            pViewmodelYStr = jsonData["playerViewmodelY"];
            svg.playerViewmodelY = std::atoi(pViewmodelYStr.c_str());

            pViewmodelZStr = jsonData["playerViewmodelZ"];
            svg.playerViewmodelZ = std::atoi(pViewmodelZStr.c_str());

            svg.checkboxRecoilCrosshair = jsonData["checkboxRecoilCrosshair"];
            svg.checkboxForceSniperCrosshair = jsonData["checkboxForceSniperCrosshair"];
            svg.checkboxWeaponDebugAccuracy = jsonData["checkboxWeaponDebugAccuracy"];
            svg.checkboxHitsound = jsonData["checkboxHitsound"];
            hitsoundStr = jsonData["selectHitsoundSound"];

            svg.checkboxKnifeModel = jsonData["checkboxKnifeModel"];

            knifemodelStr = jsonData["selectKnifeModel"];

            if (knifemodelStr == XOR("M9 Bayonet")) { svg.selectedKnifeModel = 1; }
            if (knifemodelStr == XOR("Karambit")) { svg.selectedKnifeModel = 2; }
            if (knifemodelStr == XOR("Flip")) { svg.selectedKnifeModel = 3; }
            if (knifemodelStr == XOR("Flip Ghost")) { svg.selectedKnifeModel = 4; }
            if (knifemodelStr == XOR("Gut")) { svg.selectedKnifeModel = 5; }

            if (hitsoundStr == XOR("Bameware")) { svg.selectedHitsound = 1; }
            if (hitsoundStr == XOR("Fatality")) { svg.selectedHitsound = 2; }
            if (hitsoundStr == XOR("Pop")) { svg.selectedHitsound = 3; }
            if (hitsoundStr == XOR("Punch")) { svg.selectedHitsound = 4; }
            if (hitsoundStr == XOR("Rifk7")) { svg.selectedHitsound = 5; }
            if (hitsoundStr == XOR("Skeet")) { svg.selectedHitsound = 6; }
            if (hitsoundStr == XOR("Stapler")) { svg.selectedHitsound = 7; }

            if (enemyGlowStyleStr == XOR("Outline")) { svg.enemyGlowStyle = 0; }
            if (enemyGlowStyleStr == XOR("Pulse")) { svg.enemyGlowStyle = 1; }
            if (enemyGlowStyleStr == XOR("Solid")) { svg.enemyGlowStyle = 2; }

            if (friendGlowStyleStr == XOR("Outline")) { svg.friendGlowStyle = 0; }
            if (friendGlowStyleStr == XOR("Pulse")) { svg.friendGlowStyle = 1; }
            if (friendGlowStyleStr == XOR("Solid")) { svg.friendGlowStyle = 2; }

            if (svg.isMiscEnabled) { iMisc->convars(); }
            iVisuals->mat_ambient();
        }
        else {
            res.set_content(XOR("Unable to open file"), XOR("text/plain"));
        }
        });

    svr.Get("/", [](const Request& req, Response& res)
        {
            std::ifstream file(XOR("web/redirect.html"));
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                res.set_content(buffer.str(), XOR("text/html"));
                res.set_header(XOR("Access-Control-Allow-Origin"), XOR("*"));
            }
            else
            {
                res.set_content(XOR("Unable to open file"), XOR("text/plain"));
            }
        });


    svr.listen(XOR("127.0.0.1"), 80);

    return true;
}

void server::OpenWebMenu()
{
    if (GetAsyncKeyState(VK_INSERT) & 1)
    {
        api->OpenSteamOverlayBrowser(XOR("http://127.0.0.1/"));
    }
}