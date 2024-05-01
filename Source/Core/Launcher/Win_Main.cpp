#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>


#include <thread>

#include "../Platform/SimulacraWindowsWindow.h"
#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanInstance.h"
#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanDevice.h"
#include "../../RendererBackend/Vulkan/Public/SimulacraVulkanSurface.h"


#define NUM_PROCESSORS

 bool simulacra::windows::should_exit = false;
bool try_attach_to_console()
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

    if(!try_attach_to_console())
    {
        AllocConsole();
    }
    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
    freopen_s((FILE **) stdin, "CONIN$", "r", stdin);

    simulacra::windows::window test = simulacra::windows::create_window(960, 540, "Sandbox Window");
    ShowWindow(test.hwnd_, SW_SHOW);
    vulkan_instance instance;
    vulkan_device device;
    vulkan_surface surface(instance.get_handle(), test);
    device.select_physical_device(instance);
    device.initialize_logical_device(surface.get_handle());

    MSG msg;

    while(!simulacra::windows::should_exit)
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