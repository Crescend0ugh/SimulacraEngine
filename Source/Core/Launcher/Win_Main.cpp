#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>


#include <thread>

#include "../Platform/SimulacraWindowsWindow.h"
#include "VulkanRHI.h"

#define NUM_PROCESSORS

 bool Simulacra::windows::should_exit = false;

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

    Simulacra::windows::window test = Simulacra::windows::create_window(960, 540, "Sandbox Window");
    ShowWindow(test.hwnd_, SW_SHOW);

    VulkanRHI vk_renderer {};
    vk_renderer.init(test.hwnd_);

    MSG msg;


    static std::chrono::time_point start_time = std::chrono::high_resolution_clock::now();



    while(!Simulacra::windows::should_exit)
    {
        while (PeekMessage(&msg, test.hwnd_, 0, 0, PM_REMOVE))
        {
            // Translate the message and dispatch it to WindowProc()
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        vk_renderer.test_draw_frame();
        std::chrono::time_point current_time = std::chrono::high_resolution_clock::now();
        float elapsed_time = std::chrono::duration<float, std::chrono::seconds::period>(current_time-start_time).count();
        if(elapsed_time>10)
        {
            exit(0);
        }

    }

    vk_renderer.shutdown();
    return 0;
}
