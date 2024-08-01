//
// Created by avsom on 7/26/2024.
//

#pragma once

#include <vulkan/vulkan.h>

struct VulkanDeviceAllocation
{

};

class VulkanMemoryAllocator
{
public:
    VulkanMemoryAllocator();
    ~VulkanMemoryAllocator();

    void init(VkPhysicalDevice physical_device);
    void shutdown();
    void alloc();
    void free();
    void realloc();
};
