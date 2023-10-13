//
// Created by avsom on 10/11/2023.
//

#include "../../Source/Core/Platforms/Windows/SimulacraWindows.h"
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
