//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanDevice;

class SVulkanViewport;

class SVulkanSwapchain
{

public:

    SVulkanSwapchain(VkInstance InInstance, SVulkanDevice *InDevice, void *InWindowHandle);

    ~SVulkanSwapchain() = default;

    VkSwapchainKHR GetHandle()
    { return Swapchain; }


    friend class SVulkanViewport;
    friend class SVulkanPipeline;

protected:

    VkSurfaceFormatKHR ChooseSurfaceFormat();

    VkPresentModeKHR ChoosePresentMode();

    VkExtent2D ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities);

    VkSurfaceTransformFlagBitsKHR ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities);

    VkCompositeAlphaFlagBitsKHR ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities);

    uint32 ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount);

    void CreateFramebuffers();

    uint32                        MinImageCount;
    VkSurfaceFormatKHR            SurfaceFormat;
    VkExtent2D                    ImageExtent;
    VkPresentModeKHR              PresentMode;
    VkSurfaceTransformFlagBitsKHR PreTransform;
    VkCompositeAlphaFlagBitsKHR   CompositeAlpha;


private:


    VkSwapchainKHR Swapchain;
    SVulkanDevice *Device;
    VkSurfaceKHR Surface;
    void *WindowHandle;
    std::vector<VkFramebuffer> Framebuffers;


};


