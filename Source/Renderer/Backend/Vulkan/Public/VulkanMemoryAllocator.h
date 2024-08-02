//
// Created by avsom on 7/26/2024.
//

#pragma once

#include <vulkan/vulkan.h>
#include "../Core/Sys/Precompiled.h"



struct VulkanDeviceAllocation
{
    VkDeviceMemory device_memory_;
};


class VulkanDeviceMemoryAllocator
{
public:
    VulkanDeviceMemoryAllocator();
    ~VulkanDeviceMemoryAllocator();

    void init(VkPhysicalDevice physical_device);
    void shutdown();
    VulkanDeviceAllocation alloc();
    void free(VulkanDeviceAllocation device_allocation);
    void realloc();

    VkPhysicalDevice physical_device_;
    VkDevice device_;
    VkPhysicalDeviceMemoryProperties memory_properties_;
};
