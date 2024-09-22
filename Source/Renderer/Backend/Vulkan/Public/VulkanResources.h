//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "VulkanCommon.h"

struct VulkanImage
{

    VkImage image;
    VkImageView image_view;
    VkDeviceMemory memory;
};



struct VulkanBuffer
{
    VulkanBuffer() : buffer(VK_NULL_HANDLE), memory(VK_NULL_HANDLE)
    {}
    VkBuffer       buffer;
    VkDeviceMemory memory;
};