//
// Created by avsom on 9/24/2023.
//

#ifndef SIMULACRAENGINE_WINDOWSAPPLICATION_H
#define SIMULACRAENGINE_WINDOWSAPPLICATION_H

#include <windows.h>




LRESULT CALLBACK MainWindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//
struct Win32Vars
{
    HWND hWnd;
    HINSTANCE hInstance;

};




extern Win32Vars win32;


#endif //SIMULACRAENGINE_WINDOWSAPPLICATION_H



