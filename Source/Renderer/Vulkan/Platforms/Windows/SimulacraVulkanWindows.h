//
// Created by avsom on 12/9/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H
#define SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H


#include "../../Public/SimulacraVulkanPlatform.h"
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>





class SimulacraVulkanWindows : public SimulacraVulkanPlatform
{
    static void CreateSurface(VkSurfaceKHR* Surface);
};


#endif //SIMULACRAENGINE_SIMULACRAVULKANWINDOWS_H
