//
// Created by avsom on 4/29/2024.
//

#pragma once

#include <windows.h>

bool should_exit;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_CLOSE:
            should_exit = true;
            break;

        case WM_SIZING:
            std::cout << "sizing\n";
    }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}