//
// Created by avsom on 12/29/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANLINUXPLATFORM_H
#define SIMULACRAENGINE_SIMULACRAVULKANLINUXPLATFORM_H

#include "../../Public/SimulacraVulkan.h"


class SVulkanLinuxPlatform : IVulkanPlatform
{
    static void CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance);
    static void GetPlatformExtensions();
    static void GetPlatformLayers();



};

typedef SVulkanLinuxPlatform SVulkanPlatform;


#endif //SIMULACRAENGINE_SIMULACRAVULKANLINUXPLATFORM_H
