//
// Created by avsom on 4/29/2024.
//

#pragma once

#include "SimulacraWindows.h"

namespace simulacra::windows
{

    struct window_description
    {
        int width_;
        int height_;
        int x_;
        int y_;
    };

    struct window
    {
        HWND               hwnd_;
        HINSTANCE          hinstance_;
        window_description description_;
    };

}