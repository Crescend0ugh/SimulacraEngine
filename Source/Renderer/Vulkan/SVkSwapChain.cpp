//
// Created by avsom on 10/22/2023.
//

#include "SVkSwapChain.h"


SwapChainSupportInfo QuerySwapChainSupport(VkPhysicalDevice PhysicalDevice, VkSurfaceKHR Surface) {

    SwapChainSupportInfo Information;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice, Surface,&Information.Capabilities);

    uint32 FormatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice, Surface, &FormatCount, nullptr);

    Information.Formats.resize(FormatCount);
    vkGetPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice, Surface, &FormatCount, Information.Formats.data());

    uint32 PresentModeCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice, Surface, &PresentModeCount, nullptr);

    Information.PresentModes.resize(PresentModeCount);
    vkGetPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice, Surface, &PresentModeCount, Information.PresentModes.data());


    return Information;
}
