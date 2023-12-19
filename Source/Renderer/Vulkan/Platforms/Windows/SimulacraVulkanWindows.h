//
// Created by avsom on 12/9/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H
#define SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H



#define VK_USE_PLATFORM_WIN32_KHR
#include "../../Public/SimulacraVulkan.h"





class SimulacraVulkanWindows : public SimulacraVulkanPlatform
{
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);
    static void GetPlatformExtensions();
    static void GetPlatformLayers();
};


#endif //SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H
