//
// Created by Adithya Somashekhar on 9/11/24.
//

#pragma once
#include <Application/Window.h>
#include "Platform/Mac/MacPlatformInclude.h"
#include "CocoaWindow.h"

class MacWindow : public Window
{

public:

    MacWindow() = default;

    ~MacWindow();

    virtual void initialize(uint32 width, uint32 height);

    virtual void resize();

    virtual void move();

    virtual void minimize();

    virtual void maximize();

    virtual void show_window(bool should_show);

    virtual void* native_handle();

    virtual forceinline bool is_open();

private:


    CocoaWindow* handle;

};
