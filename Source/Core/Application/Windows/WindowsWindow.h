//
// Created by avsom on 4/29/2024.
//

#pragma once


#include "Platform/Windows/WindowsPlatformInclude.h"
#include <unordered_map>
#include "CoreTypes.h"

namespace Simulacra::windows
{

    //TODO REMOVE THIS AND ADD TO A ENGINE GLOBALS FILE
    extern bool should_exit;

    static char window_class_name[] = "EngineWindow";

    struct window_description
    {
        uint32 width_;
        uint32 height_;
        uint32 x_;
        uint32 y_;
    };

    struct Window
    {
        HWND               hwnd_;
        HINSTANCE          hinstance_;
        window_description description_;

        static bool find_window_by_handle(const HWND& hwnd, Window& window)
        {
            std::unordered_map<HWND, Window>::const_iterator iterator = windows.find(hwnd);
            if(iterator == windows.end())
            {
                return false;
            }

            else
            {
                window = iterator->second;
                return true;
            }

        };

    private:
        static std::unordered_map<HWND, Window> windows;
    };

    Window create_window(uint32 width, uint32 height, const  char * title);
    void get_window_dimensions(HWND handle, uint32& width, uint32& height);




}