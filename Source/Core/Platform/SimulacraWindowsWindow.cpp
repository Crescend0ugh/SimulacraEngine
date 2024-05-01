//
// Created by avsom on 4/30/2024.
//
#include "SimulacraWindowsWindow.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_CLOSE:
            simulacra::windows::should_exit = true;
            break;

        case WM_SIZING:
            std::cout << "sizing\n";
    }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}

simulacra::windows::window simulacra::windows::create_window(uint32 width, uint32 height, const char *title)
{
    HINSTANCE hinstance = GetModuleHandle(NULL);

    WNDCLASS wc{};
    wc.hInstance     = hinstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszClassName = window_class_name;

    RegisterClass(&wc);

    uint32 WindowExStyle = 0;
    const char *ClassName  = window_class_name;
    const char *WindowName = title;
    uint32    WindowStyle = WS_OVERLAPPEDWINDOW;
    uint32    XPos        = CW_USEDEFAULT;
    uint32    YPos        = CW_USEDEFAULT;
    HWND      HWndParent  = nullptr;
    HMENU     HMenu       = nullptr;
    HINSTANCE HInstance   = hinstance;

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