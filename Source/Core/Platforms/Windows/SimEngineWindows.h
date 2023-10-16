//
// Created by avsom on 10/12/2023.
//

#ifndef SIMULACRAENGINE_SIMENGINEWINDOWS_H
#define SIMULACRAENGINE_SIMENGINEWINDOWS_H

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

struct SWin32Vars
{
    HWND Hwnd;
    HINSTANCE HInstance;
    int NCmdShow;
};


extern SWin32Vars Win32Vars;

#endif //SIMULACRAENGINE_SIMENGINEWINDOWS_H



