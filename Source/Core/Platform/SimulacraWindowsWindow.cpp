//
// Created by avsom on 4/30/2024.
//
#include "SimulacraWindowsWindow.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_CLOSE:
            Simulacra::windows::should_exit = true;
            break;

        case WM_SIZING:
            switch (wparam)
            {
                case WMSZ_BOTTOM:
                    break;
                case WMSZ_BOTTOMLEFT:
                    break;
                case WMSZ_BOTTOMRIGHT:
                    break;
                case WMSZ_LEFT:
                    break;
                case WMSZ_RIGHT:
                    break;
                case WMSZ_TOP:
                    break;
                case WMSZ_TOPLEFT:
                    break;
                case WMSZ_TOPRIGHT:
                    break;
            }


    }
    return DefWindowProc(hwnd, msg, wparam, lparam);
}

Simulacra::windows::window Simulacra::windows::create_window(uint32 width, uint32 height, const char* title)
{
    HINSTANCE hinstance = GetModuleHandle(NULL);

    WNDCLASS wc{};
    wc.hInstance     = hinstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszClassName = window_class_name;

    RegisterClass(&wc);

    uint32    WindowExStyle = 0;
    const char* ClassName   = window_class_name;
    const char* WindowName  = title;
    uint32    WindowStyle   = WS_OVERLAPPEDWINDOW;
    uint32    XPos          = CW_USEDEFAULT;
    uint32    YPos          = CW_USEDEFAULT;
    HWND      HWndParent    = nullptr;
    HMENU     HMenu         = nullptr;
    HINSTANCE HInstance     = hinstance;

    HWND hwnd = CreateWindowEx(
            WindowExStyle,
            ClassName,
            WindowName,
            WindowStyle,
            XPos,
            YPos,
            width,
            height,
            HWndParent,
            HMenu,
            HInstance,
            nullptr
    );

    return window{hwnd, hinstance, {width, height, XPos, YPos}};
}