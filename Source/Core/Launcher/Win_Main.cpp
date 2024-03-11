#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"
#include "../Globals.h"
#include "../Containers/SimulacraRingBuffer.h"
#include "../../Async/SimulacraJob.h"
#include <thread>

#include <ctime>


#define NUM_PROCESSORS




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    AllocConsole();
    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
    JobSystem System;
    System.Startup();
    System.Shutdown();

    SApplication Application = SWindowsApplication();
    SVulkanRHI   *RHI        = new SVulkanRHI();






    RHI->Init();
    while (!ShouldExitEngine)
    {
        Application.PumpMessages();
        RHI->DrawFrame();
    }

    std::cout << "Works\n";


    return 0;
}