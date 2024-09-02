//
// Created by avsom on 8/21/2024.
//

#pragma once

#include "VulkanCommon.h"

//TODO save this for later when multiple apis are needed
//struct ImageCreationInfo
//{
//    uint32                width;
//    uint32                height;
//    VkFormat              format;
//    VkImageTiling         tiling;
//    VkImageUsageFlags     usage;
//    VkMemoryPropertyFlags properties;
//};

struct VulkanBuffer
{
    VulkanBuffer() : buffer(VK_NULL_HANDLE), memory(VK_NULL_HANDLE)
    {}
    VkBuffer       buffer;
    VkDeviceMemory memory;
};

struct VulkanImage
{
    VulkanImage() : image(VK_NULL_HANDLE), image_view(VK_NULL_HANDLE), memory(VK_NULL_HANDLE)
    {}


    VkImage image;
    VkImageView image_view;
    VkDeviceMemory memory;

};

