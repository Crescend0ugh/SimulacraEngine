//
// Created by avsom on 10/12/2023.
//

#include "SimEngineWindows.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            DestroyWindow(hwnd);
            PostQuitMessage(0);
            break;
        case WM_PAINT:
            ValidateRect(hwnd, NULL);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
            break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}




