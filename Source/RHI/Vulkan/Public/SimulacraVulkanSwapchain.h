//
// Created by avsom on 10/23/2023.
//

#pragma once

#include "SimulacraVulkan.h"

class SVulkanDevice;



class SVulkanSwapchain
{

public:




    SVulkanSwapchain(VkInstance InInstance, SVulkanDevice *InDevice, void *InWindowHandle);

    ~SVulkanSwapchain() = default;

    void DestroySwapchain();

    void CreateSwapchain();

    VkSwapchainKHR &GetHandle()
    { return Swapchain; }

    void CreateImageViews();

    void CreateFramebuffers();

    void CreateRenderPass();

    VkRenderPass GetRenderPass()
    { return RenderPass; }

    uint32 & GetImageIndex()
    {
        return ImageIndex;
    }

    VkFramebuffer GetCurrFrameBuffer()
    {
        return Framebuffers[ImageIndex];
    }

    SVulkanSemaphore* GetCurrImageAcquiredSemaphore() const
    {
        return ImageAcquiredSemaphores[ImageIndex];
    }

    SVulkanSemaphore* GetCurrRenderFinishedSemaphore() const
    {
        return RenderFinishedSemaphores[ImageIndex];
    }

    SVulkanFence* GetCurrInFlightFence() const
    {
        return InFlightFences[ImageIndex];
    }

    SVulkanCommandPool* GetCommandPool() const
    {
        return CommandPool;
    }
    SVulkanCommandBuffer* GetCurrCommandBuffer() const
    {
        return CommandBuffers[ImageIndex];
    }

    VkExtent2D GetSwapchainExtent()
    { return ImageExtent; }

    void AcquireNextImage();

    void Present();

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
    uint32       BufferCount = 3;

    uint32 ImageIndex;
    uint32 SemaphoreIndex;



    VkSwapchainKHR Swapchain;
    SVulkanDevice  *Device;
    VkSurfaceKHR   Surface;
    void           *WindowHandle;



    std::vector<SVulkanCommandBuffer*> CommandBuffers;
    SVulkanCommandPool* CommandPool;

    std::vector<SVulkanSemaphore *> ImageAcquiredSemaphores;
    std::vector<SVulkanSemaphore *> RenderFinishedSemaphores;
    std::vector<SVulkanFence *>     InFlightFences;
};


