//
// Created by avsom on 12/9/2023.
//

#pragma once

#ifdef WIN32
#include "VulkanRHI.h"
#include "Application/Windows/WindowsWindow.h"

class VulkanWindowsPlatform
{
    static std::vector<const char*> get_platform_extension()
    { return {VK_KHR_WIN32_SURFACE_EXTENSION_NAME}; };

    static VkSurfaceKHR create_surface(VkInstance instance, void* handle)
    {
        VkSurfaceKHR surface;
        VkWin32SurfaceCreateInfoKHR win32_surface_create_info{};
        win32_surface_create_info.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
        win32_surface_create_info.hwnd = (HWND)handle;
        vkCreateWin32SurfaceKHR(instance, &win32_surface_create_info, nullptr, &surface);
        return surface;
    }
}

#endif
