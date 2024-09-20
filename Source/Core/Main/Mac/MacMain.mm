//
// Created by Adithya Somashekhar on 9/7/24.
//



#include "Application/Mac/MacWindow.h"
#include "Metal/MetalRHI.h"

int32 main()
{
    [NSApplication sharedApplication];

    MetalRHI metal_RHI;
    MacWindow mac_window;
    mac_window.initialize(800,450);
    std::cout << "App";
    [NSApp run];

    return 0;
}

