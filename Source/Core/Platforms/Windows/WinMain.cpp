//
// Created by avsom on 9/25/2023.
//






#include "../../Sys/Precompiled.h"
#include <windows.h>
#include <iostream>
#include "WindowsApplication.h"


Win32Vars	win32;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    std::cout << "------ Windows Initialized ------\n";
    win32.hInstance = hInstance;
    win32.nCmdShow = nCmdShow;


    std::cout<< "Build Mode: ";
#if defined(_DEBUG)
    std::cout<< "DEBUG MODE\n";

#elif defined(_NDEBUG)
    std::cout<< "RELEASE MODE\n";

#endif

    SVector2 vector = SVector2(4,8);



    return 0;
}