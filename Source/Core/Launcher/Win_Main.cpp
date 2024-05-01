#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>


#include <thread>

#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanInstance.h"
#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanDevice.h"
#include "../Platform/SimulacraWindowsWindow.h"


#define NUM_PROCESSORS


bool bAttachToConsole()
{
    if (!AttachConsole(ATTACH_PARENT_PROCESS))
    {
        if (GetLastError() != ERROR_ACCESS_DENIED) //already has a console
        {
            if (!AttachConsole(GetCurrentProcessId()))
            {
                DWORD dwLastError = GetLastError();
                if (dwLastError != ERROR_ACCESS_DENIED) //already has a console
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    if(!bAttachToConsole())
    {
        AllocConsole();
    }
    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
    printf("TEST\n");
    
    simulacra::windows::window test = simulacra::windows::create_window(960, 540, L"Sandbox Window");
    ShowWindow(test.hwnd_, SW_SHOW);
//    vulkan_instance instance;
//    vulkan_device device;
//    device.select_physical_device(instance);
//    device.initialize_logical_device();

    MSG msg;

    while(!should_exit)
    {
        while (PeekMessage(&msg, test.hwnd_, 0, 0, PM_REMOVE))
        {
            // Translate the message and dispatch it to WindowProc()
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}