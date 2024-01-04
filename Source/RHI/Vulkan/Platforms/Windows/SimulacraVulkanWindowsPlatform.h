//
// Created by avsom on 12/9/2023.
//

#pragma once




#define VK_USE_PLATFORM_WIN32_KHR
#include "../../Public/SimulacraVulkan.h"





class VulkanWindowsPlatform
{
public:
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);
    static void GetPlatformExtensions(std::vector<const char*>& OutExtensions);
    static void GetPlatformLayers();
};

typedef VulkanWindowsPlatform SVulkanPlatform;


