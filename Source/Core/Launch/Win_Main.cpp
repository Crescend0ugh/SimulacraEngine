//
// Created by avsom on 9/25/2023.
//






#include "../Sys/Precompiled.h"
#include "../Platforms/Windows/SimEngineWindows.h"
#include "../../Renderer/Renderer.h"
#include "../../Renderer/Vulkan/Temp/SVulkanRHI.h"
#include <windows.h>
#include <iostream>


SWin32Vars Win32Vars;




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{


    Win32Vars.HInstance = hInstance;
    Win32Vars.NCmdShow = nCmdShow;



   int NotPointer = 1;
   int* Pointer = &NotPointer;

std::cout << TIsPointer<int*>::Value << "\n";
    return 0;

    SVulkanRHI* RHI = new SVulkanRHI();
    RHI->Init();

}


