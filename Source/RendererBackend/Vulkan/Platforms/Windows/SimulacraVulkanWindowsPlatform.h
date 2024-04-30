//
// Created by avsom on 12/9/2023.
//

#pragma once


#include "../../Public/SimulacraVulkan.h"
#include "../../../Core/Platform/SimulacraWindowsWindow.h"
namespace simulacra::vulkan::windows

{
    VkSurfaceKHR create_surface(VkInstance instance, simulacra::windows::window& window)
    {
        VkSurfaceKHR                surface;
        VkWin32SurfaceCreateInfoKHR surface_create_info{};
        surface_create_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
        surface_create_info.hinstance = window.hinstance_;
        surface_create_info.hwnd      = window.hwnd_;
        vkCreateWin32SurfaceKHR(instance, &surface_create_info, nullptr, &surface);
        return surface;
    };
}