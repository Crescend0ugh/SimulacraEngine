//
// Created by avsom on 7/26/2024.
//

#include "VulkanMemoryAllocator.h"

VulkanMemoryAllocator::VulkanMemoryAllocator()
{
}

VulkanMemoryAllocator::~VulkanMemoryAllocator()
{
}

void VulkanMemoryAllocator::init(VkPhysicalDevice physical_device)
{
    physical_device_ = physical_device;
    VkPhysicalDeviceMemoryProperties2 memory_properties_2{};
    VkPhysicalDeviceMemoryBudgetPropertiesEXT memory_budget{};
    memory_properties_2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
    memory_properties_2.pNext = &memory_budget;
    memory_budget.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
    vkGetPhysicalDeviceMemoryProperties2(physical_device, &memory_properties_2);

    uint32 local_heaps_count     = 0;
    uint32 non_local_heaps_count = 0;

    for (VkMemoryHeap &memory_heap: memory_properties_2.memoryProperties.memoryHeaps)
    {
        if (memory_heap.size != 0)
        {
            if (memory_heap.flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) {
                local_heaps_count++;
            }
            else {
                non_local_heaps_count++;
            }
        }
    }


}

void shutdown()
{
}

VulkanDeviceAllocation VulkanMemoryAllocator::alloc()
{
}

void VulkanMemoryAllocator::free(VulkanDeviceAllocation device_allocation)
{

}

void VulkanMemoryAllocator::realloc()
{

}

void VulkanMemoryAllocator::shutdown()
{

}

void VulkanMemoryAllocator::alloc_pooled(uint32 size)
{

}

