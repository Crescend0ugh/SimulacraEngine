//
// Created by avsom on 9/25/2023.
//






#include "../Sys/Precompiled.h"
#include "../Platforms/Windows/SimEngineWindows.h"
#include "../../Renderer/Renderer.h"
#include "../../Renderer/Vulkan/Vk_Renderer.h"
#include <windows.h>
#include <iostream>


SWin32Vars Win32Vars;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{


    Win32Vars.HInstance = hInstance;
    Win32Vars.NCmdShow = nCmdShow;

    Renderer* rd = new Renderer();
    rd->Initialize();
    Vk_Renderer* Renderer = new Vk_Renderer;
    Renderer->Initialize();
    rd->RenderLoop();


    return 0;


}


