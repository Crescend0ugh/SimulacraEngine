//
// Created by avsom on 12/9/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANWINDOWSPLATFORM_H
#define SIMULACRAENGINE_SIMULACRAVULKANWINDOWSPLATFORM_H



#define VK_USE_PLATFORM_WIN32_KHR
#include "../../Public/SimulacraVulkan.h"





class VulkanWindowsPlatform : public VulkanPlatform
{
public:
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);
    static void GetPlatformExtensions();
    static void GetPlatformLayers();
};

typedef VulkanWindowsPlatform SVulkanPlatform;

#endif //SIMULACRAENGINE_SIMULACRAVULKANWINDOWSPLATFORM_H
