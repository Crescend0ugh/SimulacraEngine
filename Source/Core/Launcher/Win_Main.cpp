#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"
#include "../Globals.h"

#include <ctime>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{


    SApplication Application = SWindowsApplication();
    SVulkanRHI       *RHI         = new SVulkanRHI();



    AllocConsole();



    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
    RHI->Init();
    while (!ShouldExitEngine)
    {
        Application.PumpMessages();
        RHI->DrawFrame();
    }

    std::cout << "Works\n";
    return 0;
}