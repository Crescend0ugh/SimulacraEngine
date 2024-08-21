//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "VulkanCommon.h"


struct VulkanBuffer
{
    VkBuffer       buffer;
    VkDeviceMemory memory;
};

struct VulkanImage
{
    VkImage image;
    VkImageView image_view;
    VkDeviceMemory memory;
};
