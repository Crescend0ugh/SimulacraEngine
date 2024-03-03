#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"
#include "../Logging/SimulacraLogging.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    if (AllocConsole())
    {
        FILE* fi = 0;
        freopen_s(&fi, "CONOUT$", "w", stdout);
    }



    return 0;
}