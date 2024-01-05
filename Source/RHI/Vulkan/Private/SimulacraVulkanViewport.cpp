//
// Created by avsom on 10/23/2023.
//

#include "../Public/SimulacraVulkanViewport.h"


SVulkanViewport::SVulkanViewport(SVulkanDevice *InDevice, SVulkanSwapchain *InSwapchain) :
        Device(InDevice),
        Swapchain(InSwapchain)
{
    ImageFormat = Swapchain->ChooseSurfaceFormat().format;
    GetImagesFromSwapchain();
    CreateImageViews();
}

SVulkanViewport::~SVulkanViewport()
{
    for (auto &Image: Images)
    {
        vkDestroyImage(Device->GetHandle(), Image, nullptr);
    }

    for (auto &ImageView: ImageViews)
    {
        vkDestroyImageView(Device->GetHandle(), ImageView, nullptr);
    }

}

void SVulkanViewport::GetImagesFromSwapchain()
{
    vkGetSwapchainImagesKHR(Device->GetHandle(), *Swapchain->GetHandle(), &BufferCount, nullptr);
    Images.resize(BufferCount);
    vkGetSwapchainImagesKHR(Device->GetHandle(), *Swapchain->GetHandle(), &BufferCount, Images.data());
}

void SVulkanViewport::CreateImageViews()
{
    ImageViews.resize(Images.size());

    for(int i = 0; i < Images.size(); i++)
    {
        VkImageViewCreateInfo CreateInfo{};
        SetZeroVulkanStruct(CreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
        CreateInfo.image = Images[i];
        CreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        CreateInfo.format = ImageFormat;
        CreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        CreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        CreateInfo.subresourceRange.baseMipLevel = 0;
        CreateInfo.subresourceRange.levelCount = 1;
        CreateInfo.subresourceRange.baseArrayLayer = 0;
        CreateInfo.subresourceRange.layerCount = 1;
        VkResult Result = vkCreateImageView(Device->GetHandle(), &CreateInfo, nullptr, &ImageViews[i]);
        if(Result != VK_SUCCESS)
        {
            std::cout << "Failed to create Image View\n";
        }
    }

    std::cout << "Created swap chain images\n";
}
