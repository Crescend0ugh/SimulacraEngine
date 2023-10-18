//
// Created by avsom on 10/11/2023.
//

#include "../../Source/Core/Platforms/Windows/SimEngineWindows.h"
#include "Renderer.h"

#define CLASS_NAME "SimEngine"
void CreateWindowClasses()
{




    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = Win32Vars.HInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
}


void CreateGameWindow()
{


    CreateWindowClasses();

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            "Learn to Program Windows",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,       // Parent window
            NULL,       // Menu
            Win32Vars.HInstance,  // Instance handle
            NULL        // Additional application data
    );


    ShowWindow(hwnd, SW_SHOW);
}


bool Renderer::Initialize()
{
    CreateGameWindow();

    return true;
}

bool Renderer::Deinitialize()
{
    return false;
}

void Renderer::RenderLoop()
{
    MSG message;

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}
