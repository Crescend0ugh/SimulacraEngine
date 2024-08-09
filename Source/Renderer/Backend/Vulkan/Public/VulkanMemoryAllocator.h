//
// Created by avsom on 7/26/2024.
//

#pragma once

#include <vulkan/vulkan.h>
#include "../Core/Sys/Precompiled.h"


struct VulkanDeviceAllocation
{

};

class VulkanSubAllocator
{
    bool allocate();
};


class VulkanMemoryAllocator
{
public:
    VulkanMemoryAllocator();
    ~VulkanMemoryAllocator();

    void init(VkPhysicalDevice physical_device, VkDevice device);

    VkDeviceMemory alloc(uint32 memory_type_index, VkDeviceSize size);
    bool find_memory_type_index(VkMemoryPropertyFlags desired_memory_properties,
                                uint32 desired_memory_type_bits, uint32 &memory_type_index);


protected:

    std::vector<VulkanSubAllocator>  sub_allocators;
    VkPhysicalDevice                 physical_device_;
    VkDevice                         device_;
    VkPhysicalDeviceMemoryProperties memory_properties_;
    std::vector<uint32>              pool_sizes;
    uint32                           device_allocation_count = 0;

};
