//
// Created by avsom on 4/29/2024.
//

#pragma once

#include <string>
#include <iostream>
#include "SimulacraWindows.h"
#include "../Sys/SimulacraEngineTypes.h"

namespace simulacra::windows
{

    static wchar_t window_class_name[] = L"EngineWindow";

    struct window_description
    {
        uint32 width_;
        uint32 height_;
        uint32 x_;
        uint32 y_;
    };

    struct window
    {
        HWND               hwnd_;
        HINSTANCE          hinstance_;
        window_description description_;
    };

    window create_window(uint32 width, uint32 height, const  wchar_t* title)
    {
        HINSTANCE hinstance = GetModuleHandle(NULL);

        WNDCLASS wc{};
        wc.hInstance = hinstance;
        wc.lpfnWndProc = WndProc;
        wc.lpszClassName = window_class_name;

        RegisterClass(&wc);

        uint32      WindowExStyle = 0;
        const wchar_t* ClassName = window_class_name;
        const wchar_t* WindowName = title;
        uint32      WindowStyle = WS_OVERLAPPEDWINDOW;
        uint32         XPos = CW_USEDEFAULT;
        uint32         YPos = CW_USEDEFAULT;
        HWND        HWndParent = nullptr;
        HMENU       HMenu = nullptr;
        HINSTANCE   HInstance = hinstance;

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



}