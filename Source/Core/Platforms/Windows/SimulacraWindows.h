//
// Created by avsom on 10/12/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAWINDOWS_H
#define SIMULACRAENGINE_SIMULACRAWINDOWS_H

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

struct SWin32Vars
{
    HWND Hwnd;
    HINSTANCE HInstance;
    int NCmdShow;
};


extern SWin32Vars Win32Vars;

#endif //SIMULACRAENGINE_SIMULACRAWINDOWS_H



