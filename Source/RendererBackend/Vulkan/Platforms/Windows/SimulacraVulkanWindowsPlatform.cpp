//
// Created by avsom on 12/9/2023.
//

#include "SimulacraVulkanWindowsPlatform.h"
#include "../../../../Core/Platform/SimulacraWindowsWindow.h"

VkSurfaceKHR simulacra::vulkan::windows::create_surface(VkInstance instance, simulacra::windows::window& window)
{
    VkSurfaceKHR                surface;
    VkWin32SurfaceCreateInfoKHR surface_create_info{};
    surface_create_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surface_create_info.hinstance = GetModuleHandle(nullptr);
    surface_create_info.hwnd      = window.hwnd_;
    VkResult result = vkCreateWin32SurfaceKHR(instance, &surface_create_info, nullptr, &surface);
    std::cout<<(result != VK_SUCCESS ? "Failed to create surface\n" : "====== Created windows surface ======\n");
    return surface;
}

std::vector<vulkan_instance_extension> simulacra::vulkan::windows::get_platform_extensions()
{
    std::vector<vulkan_instance_extension> platform_extensions;
    platform_extensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
    return platform_extensions;
}



