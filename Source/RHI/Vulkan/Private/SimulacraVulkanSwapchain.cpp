//
// Created by avsom on 10/23/2023.
//

#include <functional>
#include <algorithm>
#include "../Public/SimulacraVulkanSwapchain.h"
#include "../../../Core/Math/SimulacraMathUtils.h"


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
    SwapchainCreateInfo.surface = Surface;
    SwapchainCreateInfo.minImageCount = MinImageCount;
    SwapchainCreateInfo.imageFormat = SurfaceFormat.format;
    SwapchainCreateInfo.imageColorSpace = SurfaceFormat.colorSpace;
    SwapchainCreateInfo.imageExtent = ImageExtent;
    SwapchainCreateInfo.imageArrayLayers = 1;
    SwapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    SwapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    SwapchainCreateInfo.preTransform = PreTransform;
    SwapchainCreateInfo.compositeAlpha = CompositeAlpha;
    SwapchainCreateInfo.presentMode = PresentMode;
    SwapchainCreateInfo.clipped = VK_TRUE;
    SwapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;

    VkResult Result = vkCreateSwapchainKHR(Device->GetHandle(), &SwapchainCreateInfo, nullptr, &Swapchain);

    if (Result != VK_SUCCESS)
    {
        std::cout << "Failed to create swapchain\n";
    } else
    {
        std::cout << "Created swapchain\n";
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
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(Device->GetPhysicalHandle(), Surface, &InCapabilities);
    //TODO check if the platform supports checking windows extents
    //TODO provide actual surface dimensions


    Width  = InCapabilities.currentExtent.width  == 0xFFFFFFFF ? 100 : InCapabilities.currentExtent.width;
    Height = InCapabilities.currentExtent.height == 0xFFFFFFFF ? 100 : InCapabilities.currentExtent.height;


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


