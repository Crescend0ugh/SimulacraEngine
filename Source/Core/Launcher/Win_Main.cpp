#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{



    SApplicationBase* Application = SApplication::CreateApplication();
     SVulkanRHI* RHI = new SVulkanRHI();
     RHI->Init();


    delete Application;
    std::cout << "Works\n";
    return 0;
}