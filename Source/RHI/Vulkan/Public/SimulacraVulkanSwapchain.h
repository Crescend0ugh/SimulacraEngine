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


    void AcquireNextImageIndex();
    void Present();


    SVulkanSwapchain(VkInstance InInstance, SVulkanDevice *InDevice, void *InWindowHandle);

    ~SVulkanSwapchain() = default;

    VkSwapchainKHR GetHandle()
    { return Swapchain; }

    void CreateImageViews();
    void CreateFramebuffers();
    void CreateRenderPass();

    VkRenderPass GetRenderPass() { return RenderPass; }

    VkFramebuffer GetCurrFrameBuffer() { return Framebuffers[CurrImageIndex]; }

    VkSemaphore GetCurrImageAvailableSemaphore();
    VkSemaphore GetCurrRenderFinishedSemaphore();


    VkExtent2D GetSwapchainExtent() { return ImageExtent; }

    friend class SVulkanPipeline;


private:





    VkSurfaceFormatKHR ChooseSurfaceFormat();

    VkPresentModeKHR ChoosePresentMode();

    VkExtent2D ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities);

    VkSurfaceTransformFlagBitsKHR ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities);

    VkCompositeAlphaFlagBitsKHR ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities);

    uint32 ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount);


    uint32                        MinImageCount;
    VkSurfaceFormatKHR            SurfaceFormat;
    VkExtent2D                    ImageExtent;
    VkPresentModeKHR              PresentMode;
    VkSurfaceTransformFlagBitsKHR PreTransform;
    VkCompositeAlphaFlagBitsKHR   CompositeAlpha;


    std::vector<VkImage>       Images;
    std::vector<VkImageView>   ImageViews;
    std::vector<VkFramebuffer> Framebuffers;


    VkRenderPass RenderPass;
    uint32 BufferCount = 3;

    uint32 CurrImageIndex;



    VkSwapchainKHR Swapchain;
    SVulkanDevice  *Device;
    VkSurfaceKHR   Surface;
    void           *WindowHandle;

    SVulkanSemaphore* ImageAvailableSemaphores;
    SVulkanSemaphore* RenderFinishedSemaphores;

};


