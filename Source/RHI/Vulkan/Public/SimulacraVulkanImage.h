//
// Created by avsom on 12/29/2023.
//

#ifndef SIMULACRAENGINE_SIMULACRAVULKANIMAGE_H
#define SIMULACRAENGINE_SIMULACRAVULKANIMAGE_H

#include "SimulacraVulkan.h"

struct SVulkanImage
{
    VkImageView ImageView;
    VkImage     Image;

    SVulkanImage()
    {
        ImageView = nullptr;
        Image     = nullptr;

        VkImageViewCreateInfo CreateInfo{};
        SetZeroVulkanStruct(CreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);
        CreateInfo.image = Image;
        CreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        CreateInfo.format = Swap

    }
};
#endif //SIMULACRAENGINE_SIMULACRAVULKANIMAGE_H
