//
// Created by Adithya Somashekhar on 9/11/24.
//

#pragma once

#include "Core.h"

class Window
{
public:

    virtual void initialize(uint32 width, uint32 height) = 0;

    virtual void resize() = 0;

    virtual void move() = 0;

    virtual void minimize() = 0;

    virtual void maximize() = 0;

    virtual void* native_handle() = 0;

    virtual void show_window(bool should_show) = 0;

    virtual forceinline bool is_open() { return open; }

    uint32 width;
    uint32 height;
    bool   open;
};