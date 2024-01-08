//
// Created by avsom on 12/29/2023.
//


#include "SimulacraVulkanLinuxPlatform.h"

void SVulkanLinuxPlatform::CreateSurface(void *InWindowHandle, VkSurfaceKHR *OutSurface, VkInstance InInstance)
{

}

void SVulkanLinuxPlatform::GetPlatformExtensions(std::vector<const char*>& OutExtensions)
{
    OutExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);

}

void SVulkanLinuxPlatform::GetPlatformLayers()
{

}
