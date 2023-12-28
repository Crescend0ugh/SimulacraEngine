//
// Created by avsom on 12/9/2023.
//

#include "SimulacraVulkanWindowsPlatform.h"

void VulkanWindowsPlatform::CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance)
{
    VkWin32SurfaceCreateInfoKHR Win32SurfaceCreateInfo{};
    SetZeroVulkanStruct(Win32SurfaceCreateInfo, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR);

    Win32SurfaceCreateInfo.hinstance = GetModuleHandle(nullptr);
    Win32SurfaceCreateInfo.hwnd = (HWND)InWindowHandle;

    VkResult Result = vkCreateWin32SurfaceKHR(InInstance, &Win32SurfaceCreateInfo, nullptr, OutSurface);
    if(Result != VK_SUCCESS)
    {
        std::cout << "Failed to create Vulkan Surface\n";
    }

    else
    {
        std::cout << "Created Win32 Surface\n";
    }



}

