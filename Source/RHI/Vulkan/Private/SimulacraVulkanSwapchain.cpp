//
// Created by avsom on 10/23/2023.
//

#include <functional>
#include <algorithm>
#include "../Public/SimulacraVulkanSwapchain.h"
#include "../../../Core/Math/SimulacraMathUtils.h"
#include "../../../Core/SimulacraGameViewport.h"


SVulkanSwapchain::SVulkanSwapchain(VkInstance InInstance, SVulkanDevice *InDevice, void *InWindowHandle)
{

    Device       = InDevice;
    WindowHandle = InWindowHandle;
    Surface      = nullptr;
    Swapchain    = nullptr;


    SVulkanPlatform::CreateSurface(WindowHandle, &Surface, InInstance);

    VkSurfaceCapabilitiesKHR Capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(Device->GetPhysicalHandle(), Surface, &Capabilities);


    MinImageCount  = ChooseMinImageCount(Capabilities, 3);
    SurfaceFormat  = ChooseSurfaceFormat();
    ImageExtent    = ChooseExtent(Capabilities);
    PresentMode    = ChoosePresentMode();
    PreTransform   = ChoosePreTransform(Capabilities);
    CompositeAlpha = ChooseAlphaCompositingMode(Capabilities);


    VkSwapchainCreateInfoKHR SwapchainCreateInfo;
    SetZeroVulkanStruct(SwapchainCreateInfo, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR);
    SwapchainCreateInfo.surface          = Surface;
    SwapchainCreateInfo.minImageCount    = MinImageCount;
    SwapchainCreateInfo.imageFormat      = SurfaceFormat.format;
    SwapchainCreateInfo.imageColorSpace  = SurfaceFormat.colorSpace;
    SwapchainCreateInfo.imageExtent      = ImageExtent;
    SwapchainCreateInfo.imageArrayLayers = 1;
    SwapchainCreateInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    SwapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    SwapchainCreateInfo.preTransform     = PreTransform;
    SwapchainCreateInfo.compositeAlpha   = CompositeAlpha;
    SwapchainCreateInfo.presentMode      = PresentMode;
    SwapchainCreateInfo.clipped          = VK_TRUE;
    SwapchainCreateInfo.oldSwapchain     = VK_NULL_HANDLE;

    VkResult Result = vkCreateSwapchainKHR(Device->GetHandle(), &SwapchainCreateInfo, nullptr, &Swapchain);

    if (Result != VK_SUCCESS)
    {
        std::cout << "Failed to create swapchain\n";
    } else
    {
        std::cout << "Created swapchain\n";
    }

    CreateImageViews();
    CreateRenderPass();
    CreateFramebuffers();


    CommandPool = new SVulkanCommandPool(Device, Device->GetGraphicsQueue()->GetFamilyIndex());


    ImageAcquiredSemaphores.resize(BufferCount);
    RenderFinishedSemaphores.resize(BufferCount);
    InFlightFences.resize(BufferCount);
    CommandBuffers.resize(BufferCount);

    for (int i = 0; i < BufferCount; i++)
    {
        ImageAcquiredSemaphores[i]  = new SVulkanSemaphore(Device);
        RenderFinishedSemaphores[i] = new SVulkanSemaphore(Device);
        InFlightFences[i]           = new SVulkanFence(Device);
        CommandBuffers[i]           = new SVulkanCommandBuffer(Device, CommandPool);
    }

}


VkSurfaceFormatKHR SVulkanSwapchain::ChooseSurfaceFormat()
{
    uint32 NumFormats = 0;


    vkGetPhysicalDeviceSurfaceFormatsKHR(Device->GetPhysicalHandle(), Surface, &NumFormats, nullptr);
    if (NumFormats == 0)
    {
        std::cout << "Couldn't find surface formats";
    }

    std::vector<VkSurfaceFormatKHR> SurfaceFormats(NumFormats);
    vkGetPhysicalDeviceSurfaceFormatsKHR(Device->GetPhysicalHandle(), Surface, &NumFormats, SurfaceFormats.data());

    for (const VkSurfaceFormatKHR &CurrSurfaceFormat: SurfaceFormats)
    {
        if (CurrSurfaceFormat.format == VK_FORMAT_B8G8R8A8_SRGB &&
            CurrSurfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
        {
            return CurrSurfaceFormat;
        }
    }

    return SurfaceFormats[0];
}

VkPresentModeKHR SVulkanSwapchain::ChoosePresentMode()
{
    uint32 NumPresentModes = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(Device->GetPhysicalHandle(), Surface, &NumPresentModes, nullptr);

    std::vector<VkPresentModeKHR> PresentModes(NumPresentModes);
    vkGetPhysicalDeviceSurfacePresentModesKHR(Device->GetPhysicalHandle(), Surface, &NumPresentModes,
                                              PresentModes.data());


    for (const VkPresentModeKHR &CurrPresentMode: PresentModes)
    {
        if (CurrPresentMode == VK_PRESENT_MODE_MAILBOX_KHR)
        {
            return CurrPresentMode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D SVulkanSwapchain::ChooseExtent(VkSurfaceCapabilitiesKHR InCapabilities)
{
    uint32 Width, Height;
    SGameViewport::GetWindow()->GetSize(Width, Height);
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(Device->GetPhysicalHandle(), Surface, &InCapabilities);
    //TODO check if the platform supports checking windows extents
    //TODO provide actual surface dimensions


    Width  = InCapabilities.currentExtent.width == 0xFFFFFFFF ? Width : InCapabilities.currentExtent.width;
    Height = InCapabilities.currentExtent.height == 0xFFFFFFFF ? Height : InCapabilities.currentExtent.height;


    return VkExtent2D{Width, Height};

}

VkSurfaceTransformFlagBitsKHR SVulkanSwapchain::ChoosePreTransform(VkSurfaceCapabilitiesKHR InCapabilities)
{
    if (InCapabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
    {
        return VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    } else
    {
        return InCapabilities.currentTransform;
    }
}

VkCompositeAlphaFlagBitsKHR SVulkanSwapchain::ChooseAlphaCompositingMode(VkSurfaceCapabilitiesKHR InCapabilities)
{
    if (InCapabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR)
    {
        return VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    } else
    {
        return VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;
    }
}

uint32 SVulkanSwapchain::ChooseMinImageCount(VkSurfaceCapabilitiesKHR InCapabilities, uint32 DesiredMinImageCount)
{
    return SMath::Clamp(DesiredMinImageCount, InCapabilities.minImageCount, InCapabilities.maxImageCount);
}

void SVulkanSwapchain::CreateImageViews()
{
    vkGetSwapchainImagesKHR(Device->GetHandle(), Swapchain, &BufferCount, nullptr);
    Images.resize(BufferCount);
    vkGetSwapchainImagesKHR(Device->GetHandle(), Swapchain, &BufferCount, Images.data());

    ImageViews.resize(Images.size());

    for (int i = 0; i < Images.size(); i++)
    {
        VkImageViewCreateInfo CreateInfo{};
        SetZeroVulkanStruct(CreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
        CreateInfo.image                           = Images[i];
        CreateInfo.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
        CreateInfo.format                          = SurfaceFormat.format;
        CreateInfo.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        CreateInfo.subresourceRange.baseMipLevel   = 0;
        CreateInfo.subresourceRange.levelCount     = 1;
        CreateInfo.subresourceRange.baseArrayLayer = 0;
        CreateInfo.subresourceRange.layerCount     = 1;
        VkResult Result = vkCreateImageView(Device->GetHandle(), &CreateInfo, nullptr, &ImageViews[i]);
        if (Result != VK_SUCCESS)
        {
            std::cout << "Failed to create Image View\n";
        }
    }

    std::cout << "Created swap chain images\n";
}

void SVulkanSwapchain::CreateRenderPass()
{
    VkAttachmentDescription colorAttachment{};
    colorAttachment.format         = SurfaceFormat.format;
    colorAttachment.samples        = VK_SAMPLE_COUNT_1_BIT;
    colorAttachment.loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    colorAttachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    colorAttachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    colorAttachment.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
    colorAttachment.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference colorAttachmentRef{};
    colorAttachmentRef.attachment = 0;
    colorAttachmentRef.layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass{};
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments    = &colorAttachmentRef;

    VkSubpassDependency dependency{};
    dependency.srcSubpass    = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass    = 0;
    dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.srcAccessMask = 0;
    dependency.dstStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

    VkRenderPassCreateInfo renderPassInfo{};
    renderPassInfo.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    renderPassInfo.attachmentCount = 1;
    renderPassInfo.pAttachments    = &colorAttachment;
    renderPassInfo.subpassCount    = 1;
    renderPassInfo.pSubpasses      = &subpass;
    renderPassInfo.dependencyCount = 1;
    renderPassInfo.pDependencies   = &dependency;

    if (vkCreateRenderPass(Device->GetHandle(), &renderPassInfo, nullptr, &RenderPass) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create render pass!");
    } else
    {
        std::cout << "Created Render Pass\n";
    }

}

void SVulkanSwapchain::CreateFramebuffers()
{
    Framebuffers.resize(ImageViews.size());

    for (size_t i = 0; i < ImageViews.size(); i++)
    {
        VkImageView attachments[] = {
                ImageViews[i]
        };

        VkFramebufferCreateInfo FramebufferCreateInfo;
        SetZeroVulkanStruct(FramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO);
        FramebufferCreateInfo.renderPass      = RenderPass;
        FramebufferCreateInfo.attachmentCount = 1;
        FramebufferCreateInfo.pAttachments    = attachments;
        FramebufferCreateInfo.width           = ImageExtent.width;
        FramebufferCreateInfo.height          = ImageExtent.height;
        FramebufferCreateInfo.layers          = 1;

        if (vkCreateFramebuffer(Device->GetHandle(), &FramebufferCreateInfo, nullptr, &Framebuffers[i]) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create framebuffer!");
        }


    }

    std::cout << "Created Framebuffers\n";

}

void SVulkanSwapchain::AcquireNextImage()
{
    if (vkAcquireNextImageKHR(Device->GetHandle(), Swapchain, UINT_FAST64_MAX,
                              ImageAcquiredSemaphores[SemaphoreIndex]->GetHandle(), VK_NULL_HANDLE, &ImageIndex) !=
        VK_SUCCESS)
    {
        throw std::runtime_error("Failed to acquire Image from swapchain\n");
    }

    SemaphoreIndex = (SemaphoreIndex + 1) % ImageAcquiredSemaphores.size();


}

void SVulkanSwapchain::Present()
{

    VkPresentInfoKHR PresentInfo;
    SetZeroVulkanStruct(PresentInfo, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR);

    PresentInfo.waitSemaphoreCount = 1;
    VkSemaphore WaitSemaphores = GetCurrRenderFinishedSemaphore()->GetHandle();
    PresentInfo.pWaitSemaphores = &WaitSemaphores;

    PresentInfo.swapchainCount = 1;
    PresentInfo.pSwapchains    = &Swapchain;

    PresentInfo.pImageIndices = &ImageIndex;


    vkQueuePresentKHR(Device->GetPresentQueue()->GetHandle(), &PresentInfo);
}

void SVulkanSwapchain::DestroySwapchain()
{
    vkDeviceWaitIdle(Device->GetHandle());

    //Destroy framebuffers
    for( VkFramebuffer Framebuffer : Framebuffers)
    {
        vkDestroyFramebuffer(Device->GetHandle(), Framebuffer, nullptr);
    }

    //Destroy image views
    for( VkImageView ImageView : ImageViews)
    {
        vkDestroyImageView(Device->GetHandle(), ImageView, nullptr);
    }

    vkDestroySwapchainKHR(Device->GetHandle(), Swapchain, nullptr);
}

void SVulkanSwapchain::CreateSwapchain()
{

}

