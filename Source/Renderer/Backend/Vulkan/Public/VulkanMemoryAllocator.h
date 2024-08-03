//
// Created by avsom on 7/26/2024.
//

#pragma once

#include <vulkan/vulkan.h>
#include "../Core/Sys/Precompiled.h"



struct VulkanDeviceAllocation
{
    VkDeviceMemory device_memory_;
    VkDeviceSize size_;
};

enum class PoolSize
{
    small,
    medium,
    large
};

const static uint32 pool_sizes[] =
                            {
                                    128,
                                    256,
                                    512,
                            };


struct VulkanMemoryHeap
{
};

class VulkanMemoryAllocator
{
public:
    VulkanMemoryAllocator();
    ~VulkanMemoryAllocator();

    void init(VkPhysicalDevice physical_device);
    void shutdown();
    void alloc_pooled(uint32 size);
    VulkanDeviceAllocation alloc();
    void free(VulkanDeviceAllocation device_allocation);
    void realloc();

    VkPhysicalDevice physical_device_;
    VkDevice device_;
    VkPhysicalDeviceMemoryProperties memory_properties_;
    std::vector<uint32> pool_sizes;
    uint32 device_allocation_count = 0;
    
};
