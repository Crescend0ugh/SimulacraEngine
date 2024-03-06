#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"
#include <ctime>




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{



    SApplicationBase* Application = SApplication::CreateApplication();
     SVulkanRHI* RHI = new SVulkanRHI();
     RHI->Init();
     while(true)
     {
         Application->PumpMessages();

         RHI->DrawFrame();
     }

    delete Application;
    std::cout << "Works\n";
    return 0;
}