//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanDevice;
class SVulkanViewport;

class SVulkanSwapchain {

public:

    SVulkanSwapchain(VkInstance InInstance, SVulkanDevice *InDevice, void *InWindowHandle);
    ~SVulkanSwapchain() = default;
    VkSwapchainKHR GetHandle() { return Swapchain; }




    friend class SVulkanViewport;

protected:

    VkSurfaceFormatKHR            ChooseSurfaceFormat();
    VkPresentModeKHR              ChoosePresentMode();
    VkExtent2D                    ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities);
    VkSurfaceTransformFlagBitsKHR ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities);
    VkCompositeAlphaFlagBitsKHR   ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities);
    uint32                        ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount);







private:



    VkSwapchainKHR Swapchain;
    SVulkanDevice* Device;
    VkSurfaceKHR   Surface;
    void*          WindowHandle;



};


