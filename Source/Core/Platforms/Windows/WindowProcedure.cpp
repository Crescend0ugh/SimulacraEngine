//
// Created by avsom on 9/24/2023.
//

#include <windows.h>
#include "WindowsApplication.h"
#include "../../Sys/Precompiled.h"


SIM_FORCE_INLINE void OnPositionChanged();
SIM_FORCE_INLINE void OnSize();
SIM_FORCE_INLINE void OnCreate();

LRESULT CALLBACK MainWindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

        case WM_CREATE:
        {
            //Windows.hWnd = hwnd;
        }

        case WM_DESTROY:
        {
        }

        case WM_MOVE:
        {

        }

        case WM_SIZE:
        {

        }


            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

