//
// Created by avsom on 10/22/2023.
//

#ifndef SIMULACRAENGINE_SVKSWAPCHAIN_H
#define SIMULACRAENGINE_SVKSWAPCHAIN_H
#include "../../../Core/Sys/Precompiled.h"

#include <vulkan/vulkan.h>
#include <vector>

struct SwapChainSupportInfo
{
    VkSurfaceCapabilitiesKHR Capabilities;
    std::vector<VkSurfaceFormatKHR> Formats;
    std::vector<VkPresentModeKHR> PresentModes;
};

SwapChainSupportInfo QuerySwapChainSupport(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface);




#endif //SIMULACRAENGINE_SVKSWAPCHAIN_H
