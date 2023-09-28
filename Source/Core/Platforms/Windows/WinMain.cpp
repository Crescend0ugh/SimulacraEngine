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
#if defined(_DEBUG)
std::cout<< "DEBUG MODE\n";
    float lol[4] = {1,2,3,4};
    float* test = lol;
    SVectorX testVec = SVectorX(4, lol);
    assert_2_byte_aligned(std::addressof(testVec));
#endif //DEBUG
    return 0;
}