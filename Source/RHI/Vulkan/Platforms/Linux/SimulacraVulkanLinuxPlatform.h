//
// Created by avsom on 12/29/2023.
//

#pragma once

#include "../../Public/SimulacraVulkan.h"


class SVulkanLinuxPlatform
{
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);
    static void GetPlatformExtensions(std::vector<const char*>& OutExtensions);
    static void GetPlatformLayers();



};

#ifdef USE_LINUX
typedef SVulkanLinuxPlatform SVulkanPlatform;
#endif


