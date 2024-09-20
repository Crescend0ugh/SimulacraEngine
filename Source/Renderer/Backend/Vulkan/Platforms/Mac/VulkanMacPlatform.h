//
// Created by Adithya Somashekhar on 9/8/24.
//

#pragma once

#include "Core.h"
#include "VulkanCommon.h"
#include "vulkan/vulkan_macos.h"

#define VK_USE_PLATFORM_MACOS_MVK
namespace VulkanMacPlatform
{
    static std::vector<const char*> get_platform_extension()
    { return {VK_MVK_MACOS_SURFACE_EXTENSION_NAME}; };

    static VkSurfaceKHR create_surface(VkInstance instance, void* view)
    {
        VkSurfaceKHR surface;
        VkMacOSSurfaceCreateInfoMVK mac_os_surface_create_info{};
        mac_os_surface_create_info.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
        mac_os_surface_create_info.pView = view;
        vkCreateMacOSSurfaceMVK(instance, &mac_os_surface_create_info, nullptr, &surface);
        return surface;
    }
};