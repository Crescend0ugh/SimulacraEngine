//
// Created by avsom on 12/9/2023.
//

#pragma once




#define VK_USE_PLATFORM_WIN32_KHR

#include "../../Public/SimulacraVulkan.h"



class SVulkanWindowsPlatform
{
public:
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);

    static void GetInstanceExtensions(SVulkanInstanceExtensions& OutExtensions);
    static void GetDeviceExtensions  (SVulkanDeviceExtensions&   OutExtensions);

    static void GetInstanceLayers(SVulkanInstanceLayers& OutLayers);
    static void GetDeviceLayers  (SVulkanDeviceLayers&   OutLayers);

};

typedef SVulkanWindowsPlatform SVulkanPlatform;


